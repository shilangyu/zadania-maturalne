data = []

# zbieranie danych z pliku do listy
with open('../dane/sygnaly.txt') as f:
    for x in f:
        data.append(x[:-1])

msg = ''

# zbieranie dziesiątych liter co czterdziestego słowa
for i, e in enumerate(data):
    if (i+1) % 40 == 0:
        msg += e[9]


# wyswietlenie odpowiedzi
answer = f'6.1. Przesłanie brzmi "{msg}"'
print(answer)
