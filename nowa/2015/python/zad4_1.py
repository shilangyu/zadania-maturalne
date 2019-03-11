# ladowanie danych
with open('../dane/liczby.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1])

# liczenie liczb z wieksza iloscia zer niz jedynek
more_zeros = 0
for line in data:
    zeros = 0
    ones = 0
    for char in line:
        if char == '1':
            ones += 1
        else:
            zeros += 1
    if zeros > ones:
        more_zeros += 1

# zapisanie odpowiedzi
answer = f'4.1. Liczby z wieksza iloscia zer: {more_zeros}'
print(answer)
