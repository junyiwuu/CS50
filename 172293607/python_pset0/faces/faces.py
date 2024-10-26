def convert(a):
    word = a.replace(":)", "🙂").replace(":(","🙁")
    return word

def main():
    word = input()
    conv = convert(word)
    print(conv)

main()

