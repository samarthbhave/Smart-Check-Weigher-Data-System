from machine import UART
ser = UART(1, 9600)

while True:
    try:
        ser_bytes = ser.readline(20)
        decoded_bytes = str(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
        print(decoded_bytes)
        if 'S' in decoded_bytes:
            print(decoded_bytes[2:8])
        else:
            print("Error")
            
    except:
        print("Keyboard Interrupt")
        break