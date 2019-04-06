# wczytanie napisow
with open('../dane/NAPIS.TXT') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# zbior slow rosnacych
growing = []
# przejscie po slowach
for word in data:
    # przejscie po literach i sprawdzenie czy aktualna wartosc ASCII litery jest wieksza niz poprzednej
    isgrowing = True
    prevnum = 0
    for char in word:
        if prevnum >= ord(char):
            isgrowing = False
            break
        prevnum = ord(char)

    if isgrowing:
        growing.append(word)


# wyswietlenie odpowiedzi
nl = '\n'
answer = f'5 b) Slowa rosnace: {nl}{nl.join(growing)}'
print(answer)
