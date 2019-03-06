with open('../dane/dane.txt') as f:
    data = [x[:-1].split(' ') for x in f]

brightest = 0
darkest = 256
for ln in data:
    for number in ln:
        number = int(number)
        brightest = number if number > brightest else brightest
        darkest = number if number < darkest else darkest

answer = f'6.1) Najciemniejszy: {darkest}, najjasniejszy: {brightest}'
print(answer)
