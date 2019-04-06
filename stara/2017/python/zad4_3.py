import math

# wczytanie napisow
with open('../dane/binarne.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])

# maksymalna dlugosc (czyli ograniczenie do wartosci)
maxlen = math.log2(65536)
# rekord
biggest = '0'
# przejscie po kazdym napisie
for word in data:
    # sprawdz czy nie jest za dlugie
    if len(word) <= maxlen:
        # sprawdz czy jest wiekszy
        if int(biggest, base=2) < int(word, base=2):
            biggest = word


# wyswietlenie odpowiedzi
answer = f'4.3. Najwieksza liczba mniejsza od 65536: {biggest}(2), {int(biggest, base=2)}(10)'
print(answer)
