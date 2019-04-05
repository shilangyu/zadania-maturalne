# wczytanie liczb
with open('../dane/liczby.txt') as f:
    data = []
    for number in f.readlines():
        data.append(number[:-1])


# licznik
evens = 0
# przejscie po liczbach
for number in data:
    # jezeli ostatnia cyfra jest 0 to jest parzyste
    if number[-1] == '0':
        evens += 1


# wyswietlenie odpowiedzi
answer = f'6 a) Ilosc liczb parzystych: {evens}'
print(answer)
