with open('../dane/dane.txt') as f:
    for line in f.readlines():
        data = line[:-1].split(' ')

brightest = 0
darkest = 256
for ln in data:
    for number in ln:
        number = int(number)
        brightest = number if number > brightest else brightest
        darkest = number if number < darkest else darkest

answer = f'6.1) Najciemniejszy: {darkest}, najjasniejszy: {brightest}'
print(answer)
