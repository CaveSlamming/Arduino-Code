import serial
import time

arduino = serial.Serial(port='COM5', baudrate=9600, timeout=.1)

while(True):
    if(arduino.in_waiting > 0):
        print(arduino.readLine())