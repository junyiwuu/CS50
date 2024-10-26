s = input("camelCase: ")

for char in s:
    if char.isupper():
        print(f"_{char.lower()}", end = "")
    else:
        print(char, end = "")
print()


