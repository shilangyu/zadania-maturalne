# wczytanie slow
with open('../dane/anagram.txt') as f:
    data = []
    for number in f.readlines():
        data.append(number[:-1].split(' '))


# zbior wierszy tej samej dlugosci slow
same_len = []
# przejscie po slowach
for one, two, three, four, five in data:
    # jezeli dlugosci sa takie same to zapisz
    if len(one) == len(two) == len(three) == len(four) == len(five):
        same_len.append(f'{one} {two} {three} {four} {five}')


# wyswietlenie odpowiedzi
nl = '\n'
answer = f'4 a) Wiersze z slowami o takiej samej dlugosci: {nl}{nl.join(same_len)}'
print(answer)
