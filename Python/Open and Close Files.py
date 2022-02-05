filename = input("Enter the input file name: ")
f = open(filename, "r")
array = []
for line in f:
    stripped_line = line.strip()
    line_list = stripped_line.split()
    array.append(line_list)
f.close()
order = sorted(sorted(array, reverse=True), key=str.upper)
print(order)
