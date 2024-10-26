
number = input("Number: ")
while True:
    try:
        int(number)
        break
    except ValueError:
        pass


digits = number[-2::-2]

print(digits)
