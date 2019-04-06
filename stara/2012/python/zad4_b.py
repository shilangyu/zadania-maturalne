# wczytanie slow i szyfrow
with open('../dane/sz.txt') as f:
    cyphers = []
    for word in f.readlines():
        cyphers.append(word[:-1])
with open('../dane/klucze2.txt') as f:
    keys = []
    for word in f.readlines():
        keys.append(word[:-1])


# zbior odszyfrowanych slow
words = []
# przejscie po slowach i kluczach
for cypher, key in zip(cyphers, keys):
    # zaszyfrowane slowo
    word = ''
    for i, char in enumerate(cypher):
        # odjecie ich kodow ascii plus 64 by uzyskac numer alfabetu klucza
        # klucz zawijam na wypadek krotszego klucza od szyfrowanego slowa
        currAscii = ord(char) - ord(key[i % len(key)]) + 64
        # jezeli przekroczylo dolna granice, zawijam
        if currAscii < 65:
            currAscii += 26
        word += chr(currAscii)

    words.append(word)


# wyswietlenie odpowiedzi
nl = '\n'
answer = f'4 b) Odszyfrowane slowa: {nl}{nl.join(words)}'
print(answer)
