def main():
    x = int(input("whats x? : "))
    print("x squared is ", square(x))


def square(n):
    return n * n

#make sure if import this to other file, main is not be called automatically
if __name__ == "__main__":
    main()
