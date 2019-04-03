# wczytanie slow
with open('../dane/slowa.txt') as f:
    data = []
    for pair in f.readlines():
        data.append(pair[:-1].split(' '))

# licznik
letters_ending_with_A = 0
# przejscie po kazdej parze
for a, b in data:
    # jezeli ostatnia litera w jednym lub drugim konczy sie na 'A', dodaj jeden do licznika
    if a[-1] == 'A':
        letters_ending_with_A += 1
    if b[-1] == 'A':
        letters_ending_with_A += 1


# wyswietlenie odpowiedzi
answer = f'6.1. Liczba slow konczacych sie na "A": {letters_ending_with_A}'
print(answer)
