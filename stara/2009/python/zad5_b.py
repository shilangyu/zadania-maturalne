# wczytanie napisow
with open('../dane/dane.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1].split(' '))


# licznik
BinA = 0
# przejscie po slowach
for A, B in data:
    # jezeli B slowo jest w A to zlicz
    if B in A:
        BinA += 1


# wyswietlenie odpowiedzi
answer = f'5 b) Ilosc wierszy gdzie B jest w A: {BinA}'
print(answer)
