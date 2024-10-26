def main():
    dollars = dollars_to_float(input("How much was the meal? "))
    percent = percent_to_float(input("What percentage would you like to tip? "))
    tip = dollars * percent
    print(f"Leave ${tip:.2f}")


def dollars_to_float(d):
    out = float(d.strip("$"))
    return out


def percent_to_float(p):
    out = float(p.strip("%")) / 100
    return out


main()
