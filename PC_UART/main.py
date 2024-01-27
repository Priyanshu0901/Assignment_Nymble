import serial
from datetime import datetime, timedelta
import time

def initialize_serial_port(port='COM10', baudrate=2400, timeout=1):
    ser = serial.Serial(port, baudrate=baudrate, timeout=timeout)
    return ser

def calculate_bits_per_second(start_time, total_bytes, elapsed_time):
    if elapsed_time > 0:
        bits_per_second = total_bytes * 8 / elapsed_time
        return bits_per_second
    else:
        return 0

def read_serial_data(ser):
    try:
        start_time = datetime.now()
        total_bytes_received = 0
        while True:
            serial_message = ser.readline()
            try:
                decoded_message = serial_message.decode('utf-8').strip()
                total_bytes_received += len(serial_message)
                timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
                print(f"[{timestamp}] Received: {decoded_message}")
                
                current_time = datetime.now()
                elapsed_time = (current_time - start_time).total_seconds()

                if elapsed_time >= 0.5:
                    bits_per_second = calculate_bits_per_second(start_time, total_bytes_received, elapsed_time)
                    print(f"[{timestamp}] Bits per second: {bits_per_second:.2f} bps")

                    start_time = current_time
                    total_bytes_received = 0

            except UnicodeDecodeError as e:
                timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
                print(f"[{timestamp}] Error decoding message: {e}. Hex representation: {serial_message.hex()}")

    except KeyboardInterrupt:
        print("Script terminated by user.")

def write_serial_data(ser, data):
    try:
        ser.write(data.encode('utf-8'))
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
        print(f"[{timestamp}] Sent: {data}")

    except Exception as e:
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
        print(f"[{timestamp}] Error writing data: {e}")

def close_serial_port(ser):
    ser.close()
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
    print(f"[{timestamp}] Serial port closed.")

if __name__ == "__main__":
    try:
        serial_port = initialize_serial_port()
        i=0
        data_to_write = "Hello, Serial!"
        while i<10:
            write_serial_data(serial_port, data_to_write)
            i=i+1
            time.sleep(0.3)
        
        read_serial_data(serial_port)
    finally:
        close_serial_port(serial_port)