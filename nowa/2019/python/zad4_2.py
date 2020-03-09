from math import factorial


data = [x[:-1] for x in open('../dane/liczby.txt')]


def factorial_sum(num):
    processed = []
    for x in list(num):
        processed.append(factorial(int(x)))
    return sum(processed)


numbers = []

for x in data:
    if int(x) == factorial_sum(x):
        numbers.append(x)

final_nums = '\n'.join(numbers)
answer = f'4.2. Najdluzszy ciag z NWD wiekszym niż 1 \n{final_nums}'
