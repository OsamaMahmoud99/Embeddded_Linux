import RPi.GPIO as GPIO

#set numbering system
GPIO.setmode(GPIO.BCM)

led_pin = 2
switch_pin = 3

def init() :
	#set pin direction
	GPIO.setup(switch_pin , GPIO.IN , pull_up_down=GPIO.PUD_UP)
	GPIO.setup(led_pin , GPIO.OUT)
	GPIO.output(led_pin , GPIO.LOW)


init()

while True:
	switch_state = GPIO.input(switch_pin)
	GPIO.output(led_pin , switch_state)
			
	
