a, b, c = int(input()), int(input()), int(input())
while b == 0:
    print("second value should't be 0")
    b = int(input())

print(f'result = {c % b}')
