import RPi.GPIO as GPIO
import time
from BlinkSM import BlinkSM

ledPin1 = 8
ledPin2 = 10

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(ledPin1, GPIO.OUT)
GPIO.setup(ledPin2, GPIO.OUT)

blink1 = BlinkSM(ledPin1, 0, 1000)
blink2 = BlinkSM(ledPin2,0, 1000)

stateMachines = [blink1, blink2]
tick = 100

while(True):
	for sm in stateMachines:
		if sm.elapsedTime >= sm.period:
			sm.Step()
			sm.elapsedTime = 0
		else:
			sm.elapsedTime += tick
	time.sleep(tick/1000)
