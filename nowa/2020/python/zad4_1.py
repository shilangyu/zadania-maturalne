# zaladuj dane
data = [(int(x.split()[0]), x.split()[1])
        for x in open('../dane/pary.txt')]


def is_prime(x):
    """sprawdza czy x jest liczba pierwsza"""
    if x <= 1:
        return False
    for k in range(2, x):
        if x % k == 0:
            return False

    return True


result = []

# przejdz po danych
for x, _ in data:
    # wez pod uwage tylko liczby parzyste wieksze od 4
    if x > 4 and x % 2 == 0:
        # znajdz dwie liczby pierwsze sumujace sie do x
        for i in range(x):
            if is_prime(i) and is_prime(x-i):
                result.append((x, i, x-i))
                break

# zapisz odpowiedz
formatted = '\n'.join(' '.join(map(str, x)) for x in result)
answer = f'4.1: \n{formatted}'
print(answer)
