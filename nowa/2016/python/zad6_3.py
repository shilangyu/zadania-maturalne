# ladowanie danych
with open('../dane/dane_6_3.txt') as f:
    words = []
    hashed = []
    for line in f.readlines():
        word, hash = line[:-1].split(' ')
        words.append(word)
        hashed.append(hash)


# zaszyfrowanie dana litere o dany klucz tym samym sposobem co w zad6_1.py
def crypt(letter, key):
    curr = ord(letter) - ord('A')
    moved = abs((curr + key) % (ord('Z') - ord('A') + 1))
    return chr(moved + ord('A'))


# znalezienie zle zaszyfrowanych slow
results = []
for word, hash in zip(words, hashed):
    # wydobycie klucza na podstawie pierszwej litery
    for testKey in range(ord('Z') - ord('A') + 1):
        if crypt(word[0], testKey) == hash[0]:
            key = testKey
            break
    # sprawdzenie czy reszta liter tez spelnia dany klucz
    for w, h in zip(word, hash):
        if crypt(w, key) != h:
            results.append(word)
            break

# zapisanie odpowiedzi
newline = '\n'
answer = f'6.3. Zle zaszyfrowane slowa:\n{newline.join(results)}'
print(answer)
