import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(3,GPIO.OUT,initial=GPIO.LOW)

toggle_1=0

def print_thread(): 
    while True:
        global toggle_1
        time.sleep(1)
        GPIO.output(3,toggle_1)
        toggle_1= toggle_1 ^ 1
  


print_thread()
