# wczytanie slow
with open('../dane/dane.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1])


# licznik palindromow
palis = 0
for word in data:
    # jezeli odrowcone jest takie samo to jest to palindrom
    if word[::-1] == word:
        palis += 1

# wyswietlenie odpowiedzi
answer = f'6 c) Ilosc palindromow: {palis}'
print(answer)
