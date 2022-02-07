import math
from turtle import Turtle
t = Turtle()

def drawCircle(t, length):
    for count in range(120):
        t.forward(length)
        t.left(3)

def main():
    X = 50
    Y = 75
    Radius = 100
    length = (2.0*math.pi*Radius) / 120
    distance = 2.0*math.pi*Radius
    t.up()
    t.goto(X, Y - Radius)
    t.down()
    t.pencolor(0, 0, 0)
    drawCircle(t, length)

if __name__ == "__main__":
    main()
