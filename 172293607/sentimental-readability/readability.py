import statistics

txt = input("Text: ")


# list of word
word_list = txt.split()


num_letter = 0
num_sentence = 0

for word in word_list:
    for char in word:
        if char.isalpha():
            num_letter += 1
        if char in (".", "!", "?"):
            num_sentence += 1

num_word = len(word_list)
L = num_letter / num_word * 100
S = num_sentence / num_word * 100

cl = round(0.0588 * L - 0.296 * S - 15.8)


if cl < 1:
    print("Before Grade 1")
elif cl >= 16:
    print("Grade 16+")
else:
    print(f"Grade {cl}")
