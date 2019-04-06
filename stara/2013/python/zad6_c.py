# wczytanie liczb
with open('../dane/dane.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# licznik
not_shrinking = 0
# rekordy
biggest_none_shrinking = '0'
smallest_none_shrinking = '7'*20
# przejscie po slowach
for word in data:
    # sprawdzenie czy niemaleje
    is_not_shrinking = True
    prev_num = 0
    for char in word:
        if int(char) < prev_num:
            is_not_shrinking = False
            break
        prev_num = int(char)

    if is_not_shrinking:
        not_shrinking += 1
        # jezeli pobilo rekord wielkosci zapisz
        if int(biggest_none_shrinking, base=8) < int(word, base=8):
            biggest_none_shrinking = word
        # jezeli pobilo rekord mniejszosci zapisz
        if int(smallest_none_shrinking, base=8) > int(word, base=8):
            smallest_none_shrinking = word


# wyswietlenie odpowiedzi
answer = f'6 c) Ilosc niemalejacych liczb: {not_shrinking}; Najmniejsza taka liczba: {smallest_none_shrinking}(8) {int(smallest_none_shrinking, base=8)}(10); Najwieksza taka liczba: {biggest_none_shrinking}(8) {int(biggest_none_shrinking, base=8)}(10)'
print(answer)
