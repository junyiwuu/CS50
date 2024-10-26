#use python to excute SQL

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("favorite: ")

row = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ? ", favorite)
#in SQL using question mark to replace the value
#row is temprary table

row = row[0]

print(row["n"])
