#Install the serial library first
# sudo apt-get install python-serial
import serial #Serial port API http://pyserial.sourceforge.net/pyserial_api.html
port = "/dev/ttyACM0"

SerialIOArduino = serial.Serial(port,9600) #setup the serial port and baudrate
SerialIOArduino.flushInput() #Remove old input's

while True:
    if (SerialIOArduino.inWaiting() > 0):
        inputLine = SerialIOArduino.readline().strip()  # read a '\n' terminated line()
        comands=inputLine.split(",") # Splits the line into a table/list like : ['$SW', '1', '1', '0', '0']
        print(comands)
