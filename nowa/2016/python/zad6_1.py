# ladowanie danych
with open('../dane/dane_6_1.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1])

# klucz
k = 107

# przesuniecie liter o dany klucz
results = []
for line in data:
    currLine = ''
    for char in line:
        # pozyskanie aktualnego numeru w przedziale 0-25
        curr = ord(char) - ord('A')
        # przesuniecie o dany klucz + zawiniecie o dlugosc alfabetu
        moved = (curr + k) % (ord('Z') - ord('A') + 1)
        # pozyskanie char-a + dodanie wczesniej odjetej liczba A w ASCII (by wrocic do przedzialu 65-90)
        newchar = chr(moved + ord('A'))
        currLine += newchar
    results.append(currLine)

# zapisanie odpowiedzi
newline = '\n'
answer = f'6.1. Zaszyfrowane slowa:\n{newline.join(results)}'
print(answer)
