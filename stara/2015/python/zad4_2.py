# wczytanie napisow
with open('../dane/slowa.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# licznik
twoblocks = 0
# przejscie po slowach
for word in data:
    # jezeli posortowane slowo jest takie samo co oryginal
    # i zaczyna sie zerem i konczy jedynka
    # to sklada sie z dwoch nie pustych blokow
    if sorted(word) == list(word) and word[0] == '0' and word[-1] == '1':
        twoblocks += 1


# wyswietlenie odpowiedzi
answer = f'4.2. Liczba slow ktore skladaja sie z dwoch niepustych blokow 0 -> 1: {twoblocks}'
print(answer)
