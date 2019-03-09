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
        curr = ord(char) - ord('A')
        moved = (curr + k) % (ord('Z') - ord('A') + 1)
        newchar = chr(moved + ord('A'))
        currLine += newchar
    results.append(currLine)

# zapisanie odpowiedzi
newline = '\n'
answer = f'6.1) Zaszyfrowane slowa:\n{newline.join(results)}'
print(answer)
