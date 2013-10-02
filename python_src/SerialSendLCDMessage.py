#Install the serial library first
# sudo apt-get install python-serial
import serial #Serial port API http://pyserial.sourceforge.net/pyserial_api.html
import time

port = "/dev/ttyACM0"

SerialIOArduino = serial.Serial(port,9600) #setup the serial port and baudrate
SerialIOArduino.flushInput()                #Remove old input's

time.sleep(2)   #Wait 2 sek for the Arduino to reboot before prceeding

SerialIOArduino.write("$LCD,Hello Line 1,Hello Line 2\n")

SerialIOArduino.close()

