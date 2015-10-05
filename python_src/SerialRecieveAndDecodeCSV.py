#Install the serial library first
# sudo apt-get install python-serial
import serial #Serial port API http://pyserial.sourceforge.net/pyserial_api.html
port = "/dev/ttyACM0"

SerialIOmbed = serial.Serial(port,9600) #setup the serial port and baudrate
SerialIOmbed.flushInput() #Remove old input's

while True:
    if (SerialIOmbed.inWaiting() > 0):
        inputLine = SerialIOmbed.readline().strip()  # read a '\n' terminated line()
        comands=inputLine.split(",") # Splits the line into a table/list like : ['$SW', '1', '1', '0', '0']
        print(comands)
