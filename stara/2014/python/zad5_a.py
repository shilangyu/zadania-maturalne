# wczytanie napisow
with open('../dane/NAPIS.TXT') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# licznik
primes = 0
# przejscie po slowach
for word in data:
    # sumowanie kodow ASCII
    currsum = 0
    for char in word:
        currsum += ord(char)

    # sprawdzenie czy jest to liczba pierwsza
    isprime = True
    for i in range(2, currsum//2):
        if currsum % i == 0:
            isprime = False
            break

    if isprime:
        primes += 1


# wyswietlenie odpowiedzi
answer = f'5 a) Liczba slow pierwszych: {primes}'
print(answer)
