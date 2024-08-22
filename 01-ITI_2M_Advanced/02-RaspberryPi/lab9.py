import RPi.GPIO as GPIO
import threading 
Led=2
LedState=0
def init():
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(Led,GPIO.OUT)
	GPIO.output(Led,GPIO.LOW)
LedState=0
def mycallback():
	global LedState
	global t
	if LedState==0:
		LedState=1
		GPIO.output(Led,GPIO.HIGH)
	elif LedState==1:
		LedState=0
		GPIO.output(Led,GPIO.LOW)	
	t=threading.Timer(5,mycallback)
	t.start()
	while True:
		print("yes")
	
init()
t=threading.Timer(5,mycallback)
t.start()
try:
  while True:
    print("hello")
except KeyboardInterrupt: 
  GPIO.output(Led,GPIO.LOW)
  exit()
