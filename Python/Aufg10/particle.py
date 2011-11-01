from threading import Thread
from random import random
from time import sleep

class Particle(Thread):

    def __init__(self):
        self.x = random() * (0.6 - 0.4) + 0.4;
        self.y = random() * (0.6 - 0.4) + 0.4;
        self.running = 0
        self.active = 1
        Thread.__init__(self)
        self.start()

    def getPosition(self):
        return (self.x, self.y)

    def pause(self):
        self.running = 0
        return

    def cont(self):
        self.running = 1
        return

    def stop(self):
        self.running = 0
        self.active = 0
        return

    def run(self):
        while self.active:
            while self.running:
                self.x += (1 if random() >= 0.5 else -1) * random() * 0.01
                self.y += (1 if random() >= 0.5 else -1) * random() * 0.01
                sleep(0.1)
