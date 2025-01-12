import RPi.GPIO as GPIO
import time

led_pin = 2
Btn_1 = 3
Btn_2 = 18

led_object = None
DutyCycle = 0
Freq = 10

def init() :
	global led_object , DutyCycle
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(led_pin , GPIO.OUT)
	GPIO.setup(Btn_1 , GPIO.IN , pull_up_down = GPIO.PUD_UP)
	GPIO.setup(Btn_2 , GPIO.IN , pull_up_down = GPIO.PUD_UP)
	GPIO.add_event_detect(Btn_1 , GPIO.FALLING, callback=increase)
	GPIO.add_event_detect(Btn_2 , GPIO.FALLING, callback=decrease)
	led_object = GPIO.PWM(led_pin , Freq)
	DutyCycle = 0
	led_object.start(DutyCycle)
	

def increase(pin_value) :
	global led_object , DutyCycle
	DutyCycle += 20
	
	if DutyCycle > 100 :
		DutyCycle = 100
	
	led_object.ChangeDutyCycle(DutyCycle)
	time.sleep(0.1)

def decrease(pin_value) :
	global led_object , DutyCycle
	
	
	if DutyCycle >= 20 :
		DutyCycle -= 20
	
	led_object.ChangeDutyCycle(DutyCycle)
	time.sleep(0.1)

init()

while True :
	pass
