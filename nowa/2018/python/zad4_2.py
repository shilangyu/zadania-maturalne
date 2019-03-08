data = []

# zbieranie danych z pliku do listy
with open('../dane/sygnaly.txt') as f:
    for x in f:
        data.append(x[:-1])


max_count = 0
max_word = ''

for a in data:
    # zbieranie sprawdzanego słowa do set-a zeby usunac powtarzajace sie litery
    l = len(set(a))
    if l > max_count:
        max_count = l
        max_word = a


# wyswietlenie odpowiedzi
answer = f'4.2. Slowo z najwieksza liczba liter brzmi "{max_word}" ' + \
    f'i ma {max_count} różnych liter'
print(answer)
