def main():
    time = convert(input("What time is it? "))
    if 7.0<= time <= 8.0:
        print("breakfast time")
    elif 12.00 <= time <= 13.0:
        print("lunch time")
    elif 18.0 <= time <= 19.0:
        print("dinner time")
    else:
        pass


def convert(time):
    hours, minutes = time.split(":")
    minutes = float(minutes) / 60
    time = float(hours) + minutes
    return time


if __name__ == "__main__":
    main()
