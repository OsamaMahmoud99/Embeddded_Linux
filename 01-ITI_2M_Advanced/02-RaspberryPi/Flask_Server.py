
# A very simple Flask Hello World app for you to get started with...

from flask import Flask
from flask import request
app = Flask(__name__)

pivalue = '1'
led_state = '0'
#this the page that rpi3 will lesten to it
@app.route('/')
def hello_world():
    global led_state
    return str(led_state)

#this the page that ifttt will set data, and web server will get
@app.route('/ifttt')
def Receive():
    global led_state
    led_state = str(request.get_data())
    return ''

#this the page that ifttt will set data, and web server will get
@app.route('/iftttoff')
def Receiveoff():
    global led_state
    led_state = str(request.get_data())
    return ''

#this the page that ifttt will set data, and web server will get
@app.route('/iftttexit')
def Receiveexit():
    global led_state
    led_state = str(request.get_data())
    return ''