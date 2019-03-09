# ladowanie danych
with open('../dane/liczby.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1])

# sprawdzenie dzielnosci liczb
div2 = 0
div8 = 0
for line in data:
    if line[-1] == '0':
        div2 += 1
    if line[-3:] == '000':
        div8 += 1

# zapisanie odpowiedzi
answer = f'4.2) Liczby podzielne przez 2: {div2}; Liczby podzielne przez 8: {div8}'
print(answer)
