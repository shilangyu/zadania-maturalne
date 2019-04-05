# wczytanie napisow
with open('../dane/dane.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1].split(' '))


# licznik
palis = 0
# przejscie po slowach
for A, B in data:
    # jezeli odwrocone slowo jest takie same to jest to palindrom
    if A[::-1] == A:
        palis += 1
    if B[::-1] == B:
        palis += 1


# wyswietlenie odpowiedzi
answer = f'5 a) Liczba palindromow: {palis}'
print(answer)
