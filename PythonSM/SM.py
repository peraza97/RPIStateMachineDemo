from abc import ABC, abstractmethod

class SM(ABC):
	def __init__(self, elapsedTime, period):
		self.elapsedTime = elapsedTime
		self.period = period

	@abstractmethod
	def Step(self):
		pass
