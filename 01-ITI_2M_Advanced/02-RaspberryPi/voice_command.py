import RPi.GPIO as GPIO
import requests
def init():
	GPIO.cleanup()
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(2,GPIO.OUT)
	GPIO.output(2,GPIO.LOW)

init()

data="0"
while True:
    data=requests.get("http://ELTryOsama.pythonanywhere.com/")
    if str(data.text) == 'b\'0\'':
        GPIO.output(2,GPIO.LOW)
        print("Light is off")
    elif str(data.text) == 'b\'1\'':
        GPIO.output(2,GPIO.HIGH)
        print("Light is on")
    else:
        print('Invalid Response')

print('Program finished')
GPIO.cleanup()
