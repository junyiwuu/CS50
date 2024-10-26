
total = 50


while True:
    coin = input("Insert Coin: ")

    if coin in ("25", "10", "5"):
        total = total - int(coin)

        if total >0:
            print(f"Amount Due: {total}")

        else:
            print(f"Change Owed: {abs(total)}")
            break
    else:
        print(f"Amount Due: {total}")
