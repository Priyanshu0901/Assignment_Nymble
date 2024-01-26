import serial

ser = serial.Serial('COM10', baudrate=2400, timeout=1)

try:
    while True:
        serial_message = ser.readline().decode('utf-8').strip()

        print("Received:", serial_message)

except KeyboardInterrupt:
    print("Script terminated by user.")

finally:
    ser.close()
