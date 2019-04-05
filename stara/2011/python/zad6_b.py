# wczytanie liczb
with open('../dane/liczby.txt') as f:
    data = []
    for number in f.readlines():
        data.append(number[:-1])

# rekord
biggest = '0'
# przejscie po liczbach w poszukiwania najwiekszej
for number in data:
    if int(number, base=2) > int(biggest, base=2):
        biggest = number

# wyswietlenie odpowiedzi
answer = f'6 b) Najwieksza liczba: {biggest}(2) {int(biggest, base=2)}(10)'
print(answer)
