import csv

"""
with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        favorite = row[1]
        print(favorite)

------------------------------------------

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    #treat it as dictionary
    next(reader)
    for row in reader:
        print(row["Timestamp"])

------------------------------------------

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    scratch, c, python = 0, 0, 0

    #incremental count
    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

print(f"Scratch: {scratch}  ", end = " ")
print(f"C: {c}")
print(f"python: {python}")
------------------------------------------


with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}  #empty dictionary

    for row in reader:
        favorite = row["problem"]

        #if i seen this prev, increment
        #if not, initialize 1

        if favorite in counts:
            counts[favorite] +=1
        else:
            counts[favorite] = 1

#in python, say iterate all keys, just say for __ in _dict_
for favorite in sorted(counts, key = counts.get, reverse = True): #.get: get the value
    print(f"{favorite}: {counts[favorite]}")

#sort by key (alphabetic)
------------------------------------------

from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1



for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")
------------------------------------------
"""

from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        favorite = row["problem"]
        counts[favorite] += 1

favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite]}")
