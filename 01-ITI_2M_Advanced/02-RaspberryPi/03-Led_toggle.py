import RPi.GPIO as GPIO
import threading as th


led_pin = 2
state = 0

def Toggle():
	global state
	if state == 0:
		GPIO.output(led_pin , GPIO.LOW)
	elif state == 1:
		GPIO.output(led_pin , GPIO.HIGH)
	
	state ^= 1
	
	led_toggle = th.Timer(1 , Toggle)
	led_toggle.start()


def init():
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(led_pin, GPIO.OUT)
	GPIO.output(led_pin , GPIO.LOW)

init()
Toggle()

while True:
	pass
