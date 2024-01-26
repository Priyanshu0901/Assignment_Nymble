import serial

# Replace 'COMx' with the actual serial port you are using (e.g., 'COM1' on Windows, '/dev/ttyUSB0' on Linux)
ser = serial.Serial('COM10', baudrate=2400, timeout=1)

try:
    while True:
        # Read a line from the serial port
        serial_message = ser.readline().decode('utf-8').strip()
        
        # Print the received message
        print("Received:", serial_message)

except KeyboardInterrupt:
    print("Script terminated by user.")

finally:
    # Close the serial port when done
    ser.close()
