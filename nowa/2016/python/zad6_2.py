# ladowanie danych
with open('../dane/dane_6_2.txt') as f:
    data = []
    keys = []
    for line in f.readlines():
        text, key = line[:-1].split(' ')
        if not key:
            continue
        data.append(text)
        keys.append(int(key))


# przesuniecie liter o dany klucz
results = []
for line, key in zip(data, keys):
    currLine = ''
    for char in line:
        curr = ord(char) - ord('A')
        moved = abs((curr - key) % (ord('Z') - ord('A') + 1))
        newchar = chr(moved + ord('A'))
        currLine += newchar
    results.append(currLine)

# zapisanie odpowiedzi
newline = '\n'
answer = f'6.2) Odszyfrowane slowa:\n{newline.join(results)}'
print(answer)
