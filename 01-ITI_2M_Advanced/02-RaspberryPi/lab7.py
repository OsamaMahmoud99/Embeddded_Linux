import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(2,GPIO.OUT,initial=GPIO.LOW)

toggle_1=0

def print_thread1(): 
    while True:
        global toggle_1
        time.sleep(2)
        GPIO.output(2,toggle_1)
        toggle_1= toggle_1 ^ 1
  


print_thread1()
