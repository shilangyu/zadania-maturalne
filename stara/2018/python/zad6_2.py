# wczytanie slow
with open('../dane/slowa.txt') as f:
    data = []
    for pair in f.readlines():
        data.append(pair[:-1].split(' '))

# licznik
first_in_second = 0
# przejscie po kazdej parze
for a, b in data:
    # jezeli pierwsze jest w drugim: dodaj jeden do licznika
    if a in b:
        first_in_second += 1


# wyswietlenie odpowiedzi
answer = f'6.2. Liczba wierszy gdzie pierwsze slowo jest w drugim: {first_in_second}'
print(answer)
