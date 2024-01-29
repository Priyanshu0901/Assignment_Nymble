import serial
from datetime import datetime
import asyncio

def initialize_serial_port(port='COM10', baudrate=2400, timeout=1):
    ser = serial.Serial(port, baudrate=baudrate, timeout=timeout)
    return ser

async def calculate_bits_per_second(start_time, total_bytes, elapsed_time):
    if elapsed_time > 0:
        bits_per_second = total_bytes * 8 / elapsed_time
        return bits_per_second
    else:
        return 0

async def read_serial_data(ser):
    try:
        start_time = datetime.now()
        total_bytes_received = 0
        serial_message = ser.readline()
        try:
            decoded_message = serial_message.decode('utf-8').strip()
            total_bytes_received += len(serial_message)
            timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
            print(f"[{timestamp}] Received: {decoded_message}")
            
            current_time = datetime.now()
            elapsed_time = (current_time - start_time).total_seconds()

            if elapsed_time >= 0.5:
                bits_per_second = await calculate_bits_per_second(start_time, total_bytes_received, elapsed_time)
                print(f"[{timestamp}] Bits per second: {bits_per_second:.2f} bps")
                start_time = current_time
                total_bytes_received = 0
            
            return decoded_message

        except UnicodeDecodeError as e:
            timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f")[:-3]
            print(f"[{timestamp}] Error decoding message: {e}. Hex representation: {serial_message.hex()}")

    except KeyboardInterrupt:
        print("Script terminated by user.")

async def write_serial_data(ser, data):
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


async def wait_for_response(serial_port, expected_response, timeout=5):
    start_time = datetime.now()
    while (datetime.now() - start_time).total_seconds() < timeout:
        data = await read_serial_data(serial_port)
        if expected_response in data:
            return True
        await asyncio.sleep(0.1)
    return False

async def send_packet(serial_port, packet):
    await write_serial_data(serial_port, packet)
    return await wait_for_response(serial_port, "ACK")

async def send_file(serial_port, file_path, mtu_size):
    with open(file_path, 'r') as file:
        content = file.read()
    total_size = len(content)
    start = 0
    end = mtu_size

    while start < total_size:
        packet = content[start:end]
        success = await send_packet(serial_port, packet)
        if not success:
            print("Failed to send packet. Exiting.")
            return
        start = end
        end += mtu_size
         
    await asyncio.sleep(2)
    await send_packet(serial_port, "EOF")

async def main():
    try:
        serial_port = initialize_serial_port()

        await write_serial_data(serial_port, "ACK")

        await asyncio.sleep(0.5)

        await write_serial_data(serial_port, "MTU?")
        mtu_response = await read_serial_data(serial_port)
        mtu_size = int(mtu_response[:2].strip())

        print(f"MTU Size: {mtu_size}")

        file_path = './ToSend.txt'
        await send_file(serial_port, file_path, mtu_size)

    finally:
        close_serial_port(serial_port)

if __name__ == "__main__":
    asyncio.run(main())

