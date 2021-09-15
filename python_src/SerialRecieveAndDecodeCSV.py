#Install the serial library first
# pip3 pyserial
import serial #Serial port API http://pyserial.sourceforge.net/pyserial_api.html
port = "/dev/ttyACM0"

SerialIOmbed = serial.Serial(port,9600) #setup the serial port and baudrate
SerialIOmbed.flushInput() #Remove old input's

while True:
    if (SerialIOmbed.inWaiting() > 0):
        inputLine = SerialIOmbed.readline() # read a '\n' terminated line()
        inputLine=inputLine.decode("utf-8").strip()   #Convert fro, byte to str and remove \n\r
        comands=inputLine.split(",") # Splits the line into a table/list like : ['$SW', '1', '1', '0', '0']
        print(comands)

