# wczytanie napisow
with open('../dane/binarne.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])

# licznik
double_cycle = 0
# rekord
best = ''
# przejscie po kazdym napisie
for word in data:
    # jezeli obie polowki sa takie same to napis jest dwucykliczny
    if word[:len(word)//2] == word[len(word)//2:]:
        double_cycle += 1
        # jezeli jest dluzszy niz aktualny rekord: zapisz
        if len(word) > len(best):
            best = word


# wyswietlenie odpowiedzi
answer = f'4.1. Liczba dwucyklicznych napisow: {double_cycle}; Najdluzszy taki napis: {best}; Ma dlugosc: {len(best)}'
print(answer)
