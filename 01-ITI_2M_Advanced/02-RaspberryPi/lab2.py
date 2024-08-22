#lab2 --> control on motor and led and buzzer
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(2,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(3,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(4,GPIO.OUT,initial=GPIO.LOW)
while True:
	print("|----------------------------------------|")
	print("if you want to control on motor press 1  |")
	print("if you want to control on led press 2    |")
	print("if you want to control on Buzzer press 3 |")
	print("if you want to close your system press 4 |")
	print("|----------------------------------------|")

	choice=int(input("please enter your choice:"))

	if choice==1:
		print("|----------------------------------------|")
		print("|Motor on---> enter (ON)                 |")
		print("|Motor off---> enter (OFF)               |")
		print("|----------------------------------------|")
		choiceControl=str(input("please enter your choice:"))
		if choiceControl=="ON":
			GPIO.output(2,GPIO.HIGH)
		elif choiceControl=="OFF":
			GPIO.output(2,GPIO.LOW)
		else:
			print("invalid choice")
	elif choice==2:
		print("|----------------------------------------|")
		print("|LED on---> enter (ON)                 |")
		print("|LED off---> enter (OFF)               |")
		print("|----------------------------------------|")
		choiceControl=str(input("please enter your choice:"))
		if choiceControl=="ON":
			GPIO.output(3,GPIO.HIGH)
		elif choiceControl=="OFF":
			GPIO.output(3,GPIO.LOW)
		else:
			print("invalid choice")
	elif choice==3:
		print("|----------------------------------------|")
		print("|Buzzer on---> enter (ON)                 |")
		print("|Buzzer off---> enter (OFF)               |")
		print("|----------------------------------------|")
		choiceControl=str(input("please enter your choice:"))
		if choiceControl=="ON":
			GPIO.output(4,GPIO.HIGH)
		elif choiceControl=="OFF":
			GPIO.output(4,GPIO.LOW)
		else:
			print("invalid choice")
	elif choice==4:
		print("Thank you for using My system")
		print("*******Good Bye*********")
		exit()
	else:
			print("invalid choice")
