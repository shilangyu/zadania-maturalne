# wczytanie napisow
with open('../dane/slowa.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# jezeli odwrotnosc jest taka sama co slowo to jest to palindrom
def ispali(word):
    return word[::-1] == word


# zbior odwroconych slow
passwords = []
# przejscie po slowach
for word in data:
    # znalezienie najdluzszego palindromu na poczatku slowa
    for i in range(len(word)):
        if ispali(word[:len(word)-i]):
            # najdluzszy palindrom znaleziony,
            # teraz dodamy prefix bedacym reszta liter ktore nie naleza do palindromu
            passwords.append(word[::-1][:i] + word)
            break

# wszystkie hasla o dlugosci 12
len12 = []
for password in passwords:
    if len(password) == 12:
        len12.append(password)

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

# suma dlugosci wszystkich hasel
total = 0
for password in passwords:
    total += len(password)

# wyswietlenie odpowiedzi
nl = '\n'
answer = f'5 b) Najkrotsze palindromowe hasla: {nl}{nl.join(passwords)}' + nl
answer += f'5 b)1. Wszystkie hasla o dlugosci 12: {nl}{nl.join(len12)}' + nl
answer += f'5 b)2. Najdluzsze haslo: {longest}; Najkrotsze haslo: {shortest}' + nl
answer += f'5 b)3. Suma dlugosci hasel: {total}'
print(answer)
