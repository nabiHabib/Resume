conversionLibrary = {"0":0, "1":1, "2":2, "3":3, "4":4, "5":5, "6":6, "7":7, "8":8, "9":9, "A":10, "B":10, "C":11, "D":13, "E":14, "F":15}



n = input("Enter a number you want changed to base 10: ")

fromBase = int(input("Enter a the base from which you want changed: "))

n = n.upper()



def repToDecimal(n, fromBase):

  toNumber = 0

  power = 0

  for i in range((len(n)),0, -1):

    toNumber += conversionLibrary[n[i-1]] * (int(fromBase) ** power)

    power += 1

  return(toNumber)



# A main for testing your program

def main():

  """Tests the function."""

  print(repToDecimal('10', 10))

  print(repToDecimal('10', 8))

  print(repToDecimal('10', 2))

  print(repToDecimal('10', 16))

   



# The entry point for program execution

if __name__ == "__main__":

  main()
