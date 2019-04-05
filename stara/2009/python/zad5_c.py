# wczytanie napisow
with open('../dane/dane.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1].split(' '))


# licznik
onlyglue = 0
# przejscie po slowach
for A, B in data:
    # B nie moze byc w A
    if B not in A:
        doesnt_start = True
        doesnt_end = True
        # A nie moze sie zaczynac na poszczegolne czesci B
        for i in range(len(B)):
            if A.startswith(B[i:]):
                doesnt_start = False
                break
        # A nie moze sie konczyc na poszczegolne czesci B
        for i in range(len(B)):
            if A.endswith(B[:i+1]):
                doesnt_end = False
                break
        # jezeli sie nie konczylo ani nie zaczynalo to spelnia warunki zadania
        if doesnt_end and doesnt_start:
            onlyglue += 1


# wyswietlenie odpowiedzi
answer = f'5 c) Ilosc wierszy gdzie jedyna mozliwosc stworzenia slowa C to sklejenie A i B: {onlyglue}'
print(answer)
