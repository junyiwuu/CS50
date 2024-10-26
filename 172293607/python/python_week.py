
answer = input ("whats your name");
print(f"hello, {answer} ")
#put f at the front , which is format string


#---------------------------
x = int (input ("x : "))
y = int(input ("y : "))

print(x + y)


#---------------------------
from cs50 import get_int

x = get_int("what is x? ")
y = get_int("what is y? ")

if x > y:
    print("x is bigger than y")
elif x < y:
    print("x is smaller than y")
else:
    print("x is equal to y")
#---------------------------


s = input("what is your decision: ").lower()

if s in ["y", "yes"]:
    print("agreed")
elif s in ["n", "no"]:
    print("disagreed")
#---------------------------

#uppercase whole string
#named parameters
before = input("before: ")
print("after:  ", end = "")
for _ in before:
    print(_.upper(), end="")
print()
# by default, end = "\n"
#by default, print() is printing \n
#---------------------------

before = input("before: ")
print("after:  ", end = "")
print(before.upper())
#---------------------------

before = input("before:  ")
print(f"after: {before.upper()}")

#---------------------------

for _ in range(5):
    print("meow ", end="")
print()
#---------------------------

def main():
    for i in range(3):
        meow()

def meow():
    print("meow")

main()
#still need to call the main at the end

#---------------------------

def main():
    meow(3)

def meow(n):
    for i in range(n):
        print("meow")

main()
#---------------------------

x = int(input("x: "))
y = int(input("y: "))
z = x / y
print(f"{z:.50f}")
#---------------------------

def get_int(prompt):
    return(int(input(prompt)))

def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)

main()
#---------------------------

def get_int(prompt):
    while True:
        try:
            return(int(input(prompt)))
        except ValueError:
            #print("not an integer")
            pass

def main():
    x = get_int("x: ")
    y = get_int("y: ")

    print(x + y)

main()
#---------------------------

def get_int(prompt):
    while True:
        try:
            return(int(input(prompt)))
        except ValueError:
            pass


while True:
    n = get_int("height: ")
    if n > 0:
        break
#---------------------------
from cs50 import get_int

scores = []
for i in range(3):
    score = get_int("scores: ")
    scores.append(score)

average = sum(scores) / len(scores)
print(f"average: {average:.5f}")
#---------------------------
names = ["small", "big" , "ok"]
name = input("whats the name: ")
for n in names:
    if name == n:
        print("found")
        break
else:
    print("not found")
#---------------------------
names = ["small", "big" , "ok"]
name = input("whats the name: ")
#by default using linear search
if name in names:
    print("found")

else:
    print("not found")
#---------------------------------------------------
#the list called "people" contains three dictionaries
people = [
    {"name": "david",
     "number": "234-333-532"},

     {"name": "carter",
      "number": "2934-2930-394"},

      {"name": "eli",
     "number": "234-23438-99880"},
]

#a list of dictionary
name = input("name: ")

for p in people:
    if p["name"] == name:
        number = p["number"]
        print(f"found: {number}")
        break

else:
    print("not found")
#---------------------------------------------------
people = {
    "david" : "130984-210938",
    "carter" : "123849-23487",
    "eli" : " -3455",
}

name = input("name: ")

if name in people:
    number = people[name]
    print(f"found {number}")
else:
    print("not found")
#---------------------------------------------------
import sys

if len(sys.argv) != 2:
    print("missing command line arguement")
    sys.exit(1)

print(f"hello, {sys.argv[1]}")
sys.exit(0)
#---------------------------------------------------
#pip install cowsay

import cowsay
name = input("whats your name: ")
cowsay.cow(f"this is {name}")
#---------------------------------------------------

import qrcode

img = qrcode.make("www.google.com")
img.save("qr.png", "PNG")
