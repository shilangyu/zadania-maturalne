# wczytanie slow
with open('../dane/dane.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1])


# licznik liczb parzystych
even = 0
for word in data:
    # zamieniam na male litery, potem na system dziesietny
    # i wtedy sprawdzam czy jest podzielne przez 2
    if int(word.lower(), base=16) % 2 == 0:
        even += 1

# wyswietlenie odpowiedzi
answer = f'6 b) Ilosc parzystych liczb: {even}'
print(answer)
