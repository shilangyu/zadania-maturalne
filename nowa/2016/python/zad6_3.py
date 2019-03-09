# ladowanie danych
with open('../dane/dane_6_3.txt') as f:
    words = []
    hashed = []
    for line in f.readlines():
        word, hash = line[:-1].split(' ')
        words.append(word)
        hashed.append(hash)


# przesuniecie liter o dany klucz
results = []
for word, hash in zip(words, hashed):
    bad = True
    for key in range(1, 36):
        currLine = ''
        for char in word:
            curr = ord(char) - ord('A')
            moved = abs((curr + key) % (ord('Z') - ord('A') + 1))
            newchar = chr(moved + ord('A'))
            currLine += newchar
        if currLine == hash:
            bad = False
            break
    if bad:
        results.append(word)

# zapisanie odpowiedzi
newline = '\n'
answer = f'6.3) Zle zaszyfrowane slowa:\n{newline.join(results)}'
print(answer)
