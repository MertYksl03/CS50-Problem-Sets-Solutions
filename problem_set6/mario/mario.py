from cs50 import get_int 

while True:
    heigth = get_int("Heigth: ")
    if heigth > 0 and heigth < 9:
        break
    else:
        print("Enter a number between 1 - 8")   

#print the pyramid
space = heigth -1 
box = 1 

for i in range(heigth):
    for j in range(space):
        print(" ", end="")
    for k in range(box):
        print("#", end="")
    print(" ", end="")
    for m in range(box):
        print("#", end="")
    #printing a new line 
    print("")
    box += 1
    space -= 1