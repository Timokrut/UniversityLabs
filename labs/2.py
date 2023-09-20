strings = input().split()
#  Ввести строку, вывести только слова, оканчивающиеся на согласную букву.
vowel = ['a', 'e', 'i', 'o', 'u']
for string in strings:
    if string[-1] not in vowel:
        print(string)