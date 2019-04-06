# wczytanie napisow
with open('../dane/slowa.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# licznik
lst_streak = 0
# najlepsze liczby
nums = []
# przejscie po slowach
for word in data:
    # wydobycie dlugosci bloku zer
    currbest = 0
    for segment in word.split('1'):
        currbest = max(currbest, len(segment))
    # jezeli taka sama dlugosc co rekord, dodaj
    if currbest == lst_streak:
        nums.append(word)
    # jezeli dluzsze niz rekord, wyczysc liczby, zapisz nowy rekord i dodaj siebie
    elif currbest > lst_streak:
        lst_streak = currbest
        nums = [word]


n = '\n'
# wyswietlenie odpowiedzi
answer = f'4.3. Najdluzszy blok zer: {lst_streak}; Wystepuje w slowach: {n}{n.join(nums)}'
print(answer)
