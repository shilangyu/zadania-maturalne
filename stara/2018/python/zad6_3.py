# wczytanie slow
with open('../dane/slowa.txt') as f:
    data = []
    for pair in f.readlines():
        data.append(pair[:-1].split(' '))

# licznik
anagrams = 0
# przejscie po kazdej parze
for a, b in data:
    # jezeli posortowane slowa sa takie same to sa one anagramami
    if sorted(a) == sorted(b):
        anagrams += 1


# wyswietlenie odpowiedzi
answer = f'6.3. Liczba wierszy gdzie slowa sa anagramami: {anagrams}'
print(answer)
