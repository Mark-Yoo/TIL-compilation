file = open("./test.txt")
# read method reads all text from the file as string
print(file.read())
# readline method create list with each line as an element
print(file.readlines())
# readline method also exists for to read very first line as string
print(file.readline())

# file also can be iterated with for statement
for i in file:
    print(i)