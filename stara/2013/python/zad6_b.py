# wczytanie liczb
with open('../dane/dane.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# licznik
same_ends = 0
# przejscie po slowach
for word in data:
    # najpierw zamiana na dziesietny
    word = str(int(word, base=8))
    # sprawdzenie czy pierwsza i ostatnia cyfra to to samo
    if word[0] == word[-1]:
        same_ends += 1


# wyswietlenie odpowiedzi
answer = f'6 b) Ilosc liczb gdzie pierwsza i ostatnia cyfra to to samo w systemie dzisietnym: {same_ends}'
print(answer)
