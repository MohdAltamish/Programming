sentence = input("Enter a sentence: ")

words = sentence.split()
for word in words:
    if len(word) % 2 == 0:
        reverse = word[::-1]
        result = tuple(reverse)
        print(result)