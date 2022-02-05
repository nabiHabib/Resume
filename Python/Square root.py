"""
Compute the square root of a number (uses function with loop).
1. The input is a number, or enter/return to halt the
   input process.
2. The outputs are the program's estimate of the square root
   using Newton's method of successive approximations, and
   Python's own estimate using math.sqrt.
"""

import math


# Initialize the tolerance
TOLERANCE = 0.000001

def newton(x, estimate):
    """Returns the square root of x."""
    estimate = (estimate + x / estimate) / 2
    difference = abs(x - estimate ** 2)
    if difference <= TOLERANCE:
        return estimate
    else:
        return newton(x,estimate)

def main():
    """Allows the user to obtain square roots."""
    while True:
        # Receive the input number from the user
        y = input("Enter a positive number or enter/return to quit: ")
        if y == "":
             break
        y = float(y)
        e = 1.0
        # Output the result
        print("The program's estimate is", newton(y,e))
        print("Python's estimate is     ", math.sqrt(y))

if __name__ == "__main__":
    main()
