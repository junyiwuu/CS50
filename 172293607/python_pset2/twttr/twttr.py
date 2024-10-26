s = input("Input: ")

for char in s:
    if char.lower() in ("a","e", "i", "o", "u"):
        print("", end="")
    else:
        print(char, end="")

print()
