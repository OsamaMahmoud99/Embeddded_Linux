#lab4 
import tkinter 
import RPi.GPIO as GPIO
toggle = 0 
def ConfigurationPin():
	global PinNumber_Entry
	LED=int(PinNumber_Entry.get())
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(LED,GPIO.OUT)
	toggle_function(LED)

def toggle_function(PinNumber):
    global toggle
    toggle=toggle^1
    GPIO.output(PinNumber,toggle)
 
Toggle_Window = tkinter.Tk()
Toggle_Window.title("Toggle_Window ")  
Toggle_Window.geometry("300x200")
PinNumber_Label=tkinter.Label(Toggle_Window,text="Pin Number")
PinNumber_Label.grid(row=0,column=0)
PinNumber_Entry= tkinter.Entry(Toggle_Window)
PinNumber_Entry.grid(row=0,column=1)
Toggle_Button= tkinter.Button( Toggle_Window , text = "Toggle" , command = ConfigurationPin )
Toggle_Button.grid ( row = 1 , column = 1)
tkinter.mainloop()
