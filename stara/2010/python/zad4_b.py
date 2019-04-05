# wczytanie slow
with open('../dane/anagram.txt') as f:
    data = []
    for number in f.readlines():
        data.append(number[:-1].split(' '))


# zbior wierszy anagramow
anagrams = []
# przejscie po slowach
for one, two, three, four, five in data:
    # jezeli posortowane slowa sa takie same to sa one anagramami
    if sorted(one) == sorted(two) == sorted(three) == sorted(four) == sorted(five):
        anagrams.append(f'{one} {two} {three} {four} {five}')


# wyswietlenie odpowiedzi
nl = '\n'
answer = f'4 b) Wiersze gdzie wszystkie slowa sa anagramami pierwszego: {nl}{nl.join(anagrams)}'
print(answer)
