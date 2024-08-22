import RPi.GPIO as GPIO
import time
import threading
GPIO.setmode(GPIO.BCM)
GPIO.setup(2,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(3,GPIO.OUT,initial=GPIO.LOW)
toggle_1=0
toggle_2=1

def print_thread1(num): 
    while True:
        global toggle_1
        time.sleep(2)
        GPIO.output(2,toggle_1)
        toggle_1= toggle_1 ^ 1
  
def print_thread2(num): 
    while True:
        global toggle_2
        GPIO.output(3,toggle_2)
        toggle_2= toggle_2 ^ 1
        time.sleep(1)
  
if __name__ == "__main__": 
    # creating thread 
    t1 = threading.Thread(target=print_thread2, args=(10,)) 
    t2 = threading.Thread(target=print_thread1, args=(10,)) 
  
    # starting thread 1 
    t1.start() 
    # starting thread 2 
    t2.start() 
  
    # wait until thread 1 is completely executed 
    t1.join() 
    # wait until thread 2 is completely executed 
    t2.join() 
  
    # both threads completely executed 
    print("Done!") 
