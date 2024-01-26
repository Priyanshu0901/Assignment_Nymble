import serial

ser = serial.Serial('COM10', baudrate=2400, timeout=1)


try:
    while True:
        # Read a line from the serial port
        serial_message = ser.readline()
        
        try:
            # Attempt to decode the message as UTF-8
            decoded_message = serial_message.decode('utf-8').strip()
            print("Received:", decoded_message)
        except UnicodeDecodeError as e:
            # Print the hexadecimal representation of the problematic byte
            print(f"Error decoding message: {e}. Hex representation: {serial_message.hex()}")

except KeyboardInterrupt:
    print("Script terminated by user.")

finally:
    ser.close()

