import serial
from time import sleep

ser = serial.Serial ("/dev/serial1", 115200)    #Open port with baud rate
while True:
    received_data = ser.read()              #read serial port
    data_left = ser.inWaiting()             #check for remaining byte
    received_data += ser.read(data_left)
    print (received_data)                   #print received data
    sleep(5)