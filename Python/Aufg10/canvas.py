import sys
import random
import time
from Tkinter import *
import ImageTk
from threading import Thread
import thread
thread.stack_size(2**17) # allow some more threads

RADIUS=2
WIDTH, HEIGHT = 400, 400
FPS=40
COLOR_GREEN  = "#00FF00"
COLOR_GRAY   = "#DDDDDD"
COLOR_YELLOW = "#FAFAC8"

class Timer(Thread):
    "executes a task repeatedly "

    def __init__(self, update=None, wait_time=1.0):
        Thread.__init__(self)
        self.wait_time = wait_time # in secs as float
        self.update = update
        self.running = True

    def run(self):
        while self.running:
            time.sleep(self.wait_time)
            if self.running:
                self.update()


    def cancel(self):
        self.running = False


class ObjectCanvas(Canvas):
    "draws a collection of objects supporting getPosition"
    
    def __init__(self, master=None):
        Canvas.__init__(self, master, background=COLOR_YELLOW,
                        width=WIDTH, height=HEIGHT)
        self.objects = []
        self.radius = RADIUS
        self.redrawTimer = Timer(self.update_circles, 1.0/FPS)
        self.redrawTimer.start()

    def addObject(self, obj):
        """adds an object to be drawn, 
        must support getPosition return tuple (x,y) \in [0..1],[0..1]
        """
        r = self.radius
        x,y = obj.getPosition()
        obj_id = self.create_oval(x-r, y-r, x+r*2, y+r*2, fill='gray70')
        self.objects.append((obj_id, obj))

    def getObjects(self):
        return self.objects

    def update_circles(self):
        r = self.radius
        objects = self.objects[:]
        for obj_id, obj in objects:
            x,y = obj.getPosition()
            x *= WIDTH
            y *= HEIGHT
            self.coords(obj_id, x-r, y-r, x+r*2, y+r*2)

    def cancel(self):
        self.delete(ALL) # remove all items
        self.redrawTimer.cancel()


IMG_DOT = "#define empty_width 10\n#define empty_height 10\nstatic char empty_bits[] = {\n  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, \n  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };\n"
def _get_dot(color=COLOR_GRAY):
    "create an image of a small square rectangle"
    return ImageTk.BitmapImage(background=color, data=IMG_DOT)
class OnOffButton(Checkbutton):
    "An on/off button with indicator and state variable"

    def __init__(self, master, text, command, indicator=False,
                 color_on=COLOR_GREEN, color_off=COLOR_GRAY):
        self.on_dot = _get_dot(color=color_on)
        self.off_dot = _get_dot(color=color_off)
        Checkbutton.__init__(self, master, 
                             compound=LEFT,
                             anchor=N+W,
                             padx=5,
                             pady=5,
                             text=" " + text, 
                             indicator=indicator,
                             )
        self.state = IntVar()
        if not self["indicator"]:
            self["image"] = self.off_dot
        self.command = command
        self["command"] = self.switch

    def turn_on(self):
        "turn button on"
        self.state.set(True)
        if not self["indicator"]:
            self["image"] = self.on_dot
        self.update_command()

    def turn_off(self):
        "turn button off"
        self.state.set(False)
        if not self["indicator"]:
            self["image"] = self.off_dot
        self.update_command()

    def get(self):
        "get the current state, on/off"
        return self.state.get()

    def switch(self):
        "on->off or off->on"
        if self.state.get():
            self.turn_off()
        else:
            self.turn_on()

    def update_command(self):
        "called on change of the button state"
        self.command(self.state.get())


class CanvasApp(Frame):
    """Allows to animate a collections of objects with own update_thread 
    management. Must support pause to pause the updates and cont to continue 
    the updates as well as stop to finally stop the updates.
    """
    
    def __init__(self, master=None, objectClass=None):
        Frame.__init__(self, master)
        self.objectClass = objectClass
        self.particles = []
        self.pack()
        self.create_widgets()
        self._root().protocol("WM_DELETE_WINDOW", self.endit)


    def create_widgets(self):
        left = Frame(self)
        left.grid(row=0, column=0, sticky=N+S)
        right = Frame(self)
        right.grid(row=0, column=1, sticky=N+S)
        quit_button = Button(left, text="Quit")
        quit_button["command"] = self.endit
        quit_button.grid(row=0, sticky=E+W)
        add_button = Button(left, text="Add")
        add_button["command"] = self.add
        add_button.grid(row=1, sticky=E+W)
        add_button10 = Button(left, text="Add 10")
        add_button10["command"] = lambda : self.add(no=10)
        add_button10.grid(row=2, sticky=E+W)
        self.animate_button = OnOffButton(left, text="Animate",
                                          command=self.animate)
        self.animate_button.grid(row=4, sticky=E+W)
        left.rowconfigure(4, weight=1)
        self.label = Label(left, text="Objekte: 0")
        self.label.grid(row=6, sticky=E+W)
        self.canvas = ObjectCanvas(right)
        self.canvas.pack()

    def add(self, no=1):
        for i in range(no):
            obj = self.objectClass()
            self.canvas.addObject(obj)
            if self.animate_button.get():
                obj.cont()
        self.label["text"] = "Objekte: %d" % len(self.canvas.getObjects())

    def animate(self, checked):
        if checked:
            print "continue updating of particles"
            for _, obj in self.canvas.getObjects():
                obj.cont()
        else:
            print "pause updating of particles"
            for _, obj in self.canvas.getObjects():
                obj.pause()

    def endit(self):
        self.canvas.cancel()
        for _, obj in self.canvas.getObjects():
            obj.stop()
        time.sleep(0.2)
        self._root().quit()
        self._root().destroy()


if __name__ == '__main__':
    root = Tk()
    import particle
    app = CanvasApp(root, particle.Particle)
    app.mainloop()

