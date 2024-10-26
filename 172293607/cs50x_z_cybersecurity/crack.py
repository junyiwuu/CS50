from string import digits
from itertools import product #combination


for passcode in product(digits, repeat=4):
    print(passcode)


# sdsd
