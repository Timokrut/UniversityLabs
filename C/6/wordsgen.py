from random import randint

def generatewords():
    number_of_words = randint(50, 100)
    alphabet = 'qwertyuiopasdfghjklzxcvbnm'
    answer = ''
    for _ in range(number_of_words):
        answer += alphabet[randint(0, len(alphabet) - 1)] * randint(1, 15) + ' '

    print('succesfully filled')
    
    return answer

with open('file1.txt', 'w') as first, open('file2.txt', 'w') as second, open('file3.txt', 'w') as third:
    first.write(generatewords())
    second.write(generatewords())
    third.write(generatewords())
