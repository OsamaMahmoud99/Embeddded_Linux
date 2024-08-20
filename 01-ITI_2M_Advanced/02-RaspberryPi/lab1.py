#lab1--> led on off
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(2,GPIO.OUT)
GPIO.setup(3,GPIO.OUT)

try:
	
	while True:
		x=str(input("please enter the value:"))

		if x=="ON":
			GPIO.output(2,GPIO.HIGH)
			GPIO.output(3,GPIO.HIGH)
		elif x=="OFF":
			GPIO.output(2,GPIO.LOW)
			GPIO.output(3,GPIO.LOW)	
		else:
			print("invallid value, try again")
except KeyboardInterrupt:
		print("\nprogram interrupted by user")
		GPIO.output(2,GPIO.LOW)

