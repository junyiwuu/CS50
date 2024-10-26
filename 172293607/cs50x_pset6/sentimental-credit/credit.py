import cs50
import sys
number = input("Number: ")
while True:

    try:
        int(number)
        break
    except ValueError:
        pass

# test number avalibility

digits = number[-2::-2]

int_list = []
for digit in digits:
    double = int(digit)*2
    if double > 9:
        int_list.append(double//10)
        int_list.append(double % 10)
    else:
        int_list.append(double)

sum_list = sum(int_list)

# ------other digits

digits_other = number[-1::-2]

int_list_other = []
for digit in digits_other:
    int_list_other.append(int(digit))

sum_other = sum(int_list_other)

sum_overall = sum_list+sum_other
if sum_overall % 10 != 0:
    print("INVALID")
    sys.exit()
else:
    pass

start_two = number[:2]
start_one = number[:1]
match start_two:
    case "34" | "37":
        if len(number) == 15:
            print("AMEX")

    case "51" | "52" | "53" | "54" | "55":
        if len(number) == 16:
            print("MASTERCARD")

    case _:
        match start_one:
            case "4":
                if len(number) == 13 or len(number) == 16:
                    print("VISA")
                else:
                    print("INVALID")
            case _:
                print("INVALID")
