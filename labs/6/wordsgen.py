from random import randint

number_of_words = randint(50, 100)
print(number_of_words)
alphabet = 'qwertyuiopasdfghjklzxcvbnm'

answer = ''

for word in range(number_of_words):
    answer += alphabet[randint(0, len(alphabet) - 1)] * randint(1, 15) + ' '


print(answer)    