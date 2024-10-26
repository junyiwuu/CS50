def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):

    #check length between 2 and 6
    if 2 <= len(s) <=6:

        #check start with two letter
        for char in s[0:2]:
            if char.isalpha():
                pass
            else:
                return 0


        #check punctuatio


        #check numbers in the middle

        #if there is a number in the end, then check middle
        stripstr = s.strip("0123456789")
        if len(stripstr) == len(s):

        for char in s:
            if char.isdigit():






    else:
        return 0
    for i in range(len(s)):
        if s[]
