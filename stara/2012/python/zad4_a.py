# wczytanie slow i szyfrow
with open('../dane/tj.txt') as f:
    words = []
    for word in f.readlines():
        words.append(word[:-1])
with open('../dane/klucze1.txt') as f:
    keys = []
    for word in f.readlines():
        keys.append(word[:-1])


# zbior zaszyfrowanych slow
cyphers = []
# przejscie po slowach i kluczach
for word, key in zip(words, keys):
    # zaszyfrowane slowo
    cypher = ''
    for i, char in enumerate(word):
        # dodanie ich kodow ascii minus 64 by uzyskac numer alfabetu klucza
        # klucz zawijam na wypadek krotszego klucza od szyfrowanego slowa
        currAscii = ord(char) + ord(key[i % len(key)]) - 64
        # jezeli przekroczylo gorna granice, zawijam
        if currAscii > 90:
            currAscii -= 26
        cypher += chr(currAscii)

    cyphers.append(cypher)


# wyswietlenie odpowiedzi
nl = '\n'
answer = f'4 a) Zaszyfrowane slowa: {nl}{nl.join(cyphers)}'
print(answer)
