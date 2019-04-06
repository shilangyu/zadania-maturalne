# wczytanie liczb
with open('../dane/liczby.txt') as f:
    data = []
    for number in f.readlines():
        data.append(number[:-1])

# licznik
len9 = 0
# suma liczb o dlugosci 9
sum9 = 0
# przejscie po liczbach
for number in data:
    # jezeli ma dlugosc 9 dodaj do sumy i zlicz
    if len(number) == 9:
        len9 += 1
        sum9 += int(number, base=2)

# wyswietlenie odpowiedzi
answer = f'6 c) Ilosc liczb o dlugosci 9: {len9}; Suma tych liczb w binarnym: {bin(sum9)[2:]}(2)'
print(answer)
