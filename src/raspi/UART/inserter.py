# coding=utf-8
import serial
from time import sleep
from influxdb import InfluxDBClient

client = InfluxDBClient(host='127.0.0.1', port=8086, username='phillip', password='password')
client.switch_database('tmp36')

try:
        ser = serial.Serial ("/dev/serial1", 115200)    #Open port with baud rate
        while True:
                received_data = ser.read()              #read serial port
                data_left = ser.inWaiting()             #check for remaining byte
                received_data += ser.read(data_left)
                print(float(received_data))             #print received data
                val = float(received_data)
                client.write_points([{"measurement": "temperature", "fields": {"value": val}}])
                sleep(5)
except: # catcht alle Exceptions wie z.b. KeyboardInterrupt z.b. wenn man Strg + C drueckt
        print('bye :)')         # immer schoen brav die ressources schließen
        ser.close()
        client.close()