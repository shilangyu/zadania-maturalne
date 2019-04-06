# wczytanie napisow
with open('../dane/slowa.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# zbior odwroconych slow
passwords = []
# przejscie po slowach
for word in data:
    passwords.append(word[::-1])

# rekordy
shortest = 'A'*100
longest = ''
for password in passwords:
    # jezeli jest dluzsze zapisz jako nowy rekord
    if len(password) > len(longest):
        longest = password
    # jezeli jest krotsze zapisz jako nowy rekord
    if len(password) < len(shortest):
        shortest = password


# wyswietlenie odpowiedzi
nl = '\n'
answer = f'5 a) Odwrocone slowa (hasla): {nl}{nl.join(passwords)}' + nl
answer += f'Najdluzsze haslo: {longest}; Jego dlugosc: {len(longest)}; Najkrotsze haslo: {shortest}; Jego dlugosc: {len(shortest)}'
print(answer)
