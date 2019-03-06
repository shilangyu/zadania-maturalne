with open('../dane/dane.txt') as f:
    for line in f.readlines():
        data = line[:-1].split(' ')

brightest = 0
darkest = 256
for ln in data:
    for number in ln:
        number = int(number)
        if number > brightest:
            brightest = number
        if number < darkest:
            darkest = number

answer = f'6.1) Najciemniejszy: {darkest}, najjasniejszy: {brightest}'
print(answer)
