from Enums import BlinkStates
from SM import SM
import RPi.GPIO as GPIO

class BlinkSM(SM):
	def __init__(self, ledPin, elapsedTime, period):
		super().__init__(elapsedTime, period)
		self.ledPin = ledPin
		self.State = BlinkStates.OFF

	def Step(self):
		#transition
		if self.State == BlinkStates.OFF:
			self.State = BlinkStates.ON
		else: 
			self.State = BlinkStates.OFF	
		#action
		if self.State == BlinkStates.OFF:
			GPIO.output(self.ledPin, GPIO.LOW)
		else: 	
			GPIO.output(self.ledPin, GPIO.HIGH)
