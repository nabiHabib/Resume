def main():
    lyst = [3, 1, 7, 1, 4, 10]
    print("List: ", lyst)
    mode(lyst)
    median(lyst)
    mean(lyst) 

def mode(x):
    if len(x) == 0:
        return 0
    print("Mode: % s" % (max(set(x), key = x.count)))

def median(x):
    if len(x) == 0:
        return 0
    midpoint = len(x)//2
    x.sort()
    print("Median:", end = " ")
    if len(x) % 2 ==1:
        print(x[midpoint])
    else:
        print((x[midpoint] + x[midpoint -1]) / 2)

def mean(x):
    if len(x) == 0:
        return 0
    avg = sum(x) / len(x) 
    print("Mean: ", avg)  

if __name__ == "__main__":
    main()
