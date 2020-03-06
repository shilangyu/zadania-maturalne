from math import factorial


def factorial_sum(num) -> int:
    return sum(map(lambda x: factorial(int(x)), list(num)))


data = [x[:-1] for x in open('../dane/liczby.txt')]

numbers = []

for x in data:
    if int(x) == factorial_sum(x):
        numbers.append(x)

final_nums = '\n'.join(numbers)
answer = f'4.2. Najdluzszy ciag z NWD wiekszym niż 1 \n{final_nums}'
