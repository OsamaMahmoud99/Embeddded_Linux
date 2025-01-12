import RPi.GPIO as GPIO
import tkinter as tk

led_pin = 2
led_state = 0

def init():
	global led_state , PinEntry, led_pin
	
	led_pin = int(PinEntry.get())
	GPIO.setup(led_pin, GPIO.OUT)
	GPIO.output(led_pin , GPIO.LOW)
	
	led_state = 0

def Toggle():
	global led_state , led_pin
	if led_state == 0:
		GPIO.output(led_pin , GPIO.LOW)
	elif led_state == 1:
		GPIO.output(led_pin , GPIO.HIGH)
	
	led_state ^= 1

#pre-main code
root = tk.Tk()
root.title("led_toggle")
root.geometry("640x400")
root.resizable(False , False)

#Button_toggle
Tgl_Btn = tk.Button(root, text="Toggle_led", command=Toggle)
Tgl_Btn.place(x=300,y=40)

#Button_init
Init_Btn = tk.Button(root, text="Init_pin", command=init)
Init_Btn.place(x=30,y=40)

#text Entry
PinEntry = tk.Entry(root, width=50, fg="purple")
PinEntry.insert(0 , "Enter pin number")
PinEntry.place(x=45, y=20)

GPIO.setmode(GPIO.BCM)

root.mainloop()
GPIO.cleanup()
