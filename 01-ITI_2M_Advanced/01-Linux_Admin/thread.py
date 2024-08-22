import threading 
import time 
therad1_counter=0
therad2_counter=0
def print_thread1(num): 
    """ 
    function to print cube of given num 
    """
    while True:
        print("Hi thread 1")
        time.sleep(1)
  
def print_thread2(num): 
    """ 
    function to print square of given num 
    """
    while True:
        print("Hi thread 2") 
        time.sleep(1)
  

# creating thread 
t1 = threading.Thread(target=print_thread1, args=(10,)) 
t2 = threading.Thread(target=print_thread2, args=(10,)) 

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