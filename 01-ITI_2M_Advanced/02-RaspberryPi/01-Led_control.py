import RPi.GPIO as GPIO

led_pin = 2
#set numbering system
GPIO.setmode(GPIO.BCM)
#set pin direction
GPIO.setup(led_pin , GPIO.OUT)

while True:
	x =input("Enter ON/OFF: ")
	if x == "ON" :
		GPIO.output(led_pin , GPIO.HIGH)
	elif x == "OFF" :
		GPIO.output(led_pin , GPIO.LOW)
	elif x == "DONE" :
		GPIO.cleanup()
		break
	else:
		print("wrong configurations")
			
	
