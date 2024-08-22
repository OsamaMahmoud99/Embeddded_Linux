#lab3--> control on led using GUI  
import RPi.GPIO as GPIO
import tkinter

toggle_flag=1

def tog():
    global toggle_flag
    if toggle_flag == 1:
        GPIO.output(2, GPIO.HIGH)
        toggle_flag = 0 
    elif toggle_flag == 0:
        GPIO.output(2, GPIO.LOW)
        toggle_flag = 1

GPIO.setmode(GPIO.BCM)
GPIO.setup(2,GPIO.OUT, initial=GPIO.LOW)


mainwindow =tkinter.Tk()
mainwindow.geometry("350x300+100+50")
mainwindow.title("## LED ##")

button1= tkinter.Button(mainwindow, width= '15', text= 'toggle', command = tog)
button1.grid(row=1, column=1 )
mainwindow.mainloop()
