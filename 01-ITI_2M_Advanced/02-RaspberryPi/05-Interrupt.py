import RPi.GPIO as GPIO
import time

led_pin = 2
Btn_1 = 3
Btn_2 = 18
led_state = 0;
def init() :
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(led_pin , GPIO.OUT)
	GPIO.setup(Btn_1 , GPIO.IN , pull_up_down = GPIO.PUD_UP)
	GPIO.setup(Btn_2 , GPIO.IN , pull_up_down = GPIO.PUD_UP)
	GPIO.add_event_detect(Btn_1 , GPIO.FALLING, callback=turnon)
	GPIO.add_event_detect(Btn_2 , GPIO.FALLING, callback=turnoff)
	

def turnon(value) :
		GPIO.output(led_pin , GPIO.HIGH)
		print("turn on value = ",value)
		time.sleep(0.2)

def turnoff(value) :
		GPIO.output(led_pin , GPIO.LOW)
		print("turn off value = ",value)
		time.sleep(0.2)
init()

while True:
	pass
