while True:
    try:
        height = int(input("Height: "))
        if (height > 0) and (height < 9):
            break
        else:
            print("please re enter the height")
    except ValueError:
        print("not a valid number, please re-enter")


for i in range(int(height)):

    for j in range (int(height)-i-1):
        print(" ", end="")

    for j in range (i+1):
        print("#", end="")


    print("  ", end = "")
        #print("#", end="")

    for j in range (i+1):
        print("#", end="")


    print()
