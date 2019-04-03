# wczytanie napisow
with open('../dane/slowa.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# licznik
morezeros = 0
# przejscie po slowach
for word in data:
    # sumowanie cyfr
    currsum = 0
    for char in word:
        currsum += int(char)

    # jezeli suma cyfr jest mniejsza od polowy dlugosci slowa to spelnia warunek zadania
    if currsum < len(word)/2:
        morezeros += 1


# wyswietlenie odpowiedzi
answer = f'4.1. Liczba slow z wieksza iloscia zer niz jedynek: {morezeros}'
print(answer)
