text = "ab12cd34ef"
digits = []
for char in text:
    if char.isdigit():
        digits.append(int(char))
digits.reverse()
result = tuple(digits)

print(result)