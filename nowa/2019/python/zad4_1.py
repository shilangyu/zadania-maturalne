# zaladuj dane
data = [int(x[:-1]) for x in open('../dane/liczby.txt')]


def is_power_of(x, n):
    """sprawdza czy x jest potega liczby n"""

    # najpierw wyeliminowac 2 przypadki gdzie wiadomo ze liczba napewno spelnia lub nie spelnia warukow
    if x == 1:
        return True
    if x % n != 0:
        return False
    # dzielic liczbe x az bedzie sie rownala (badz nie) n
    while x >= n:
        if x == n:
            return True
        x /= n
    return False


count = 0

# przejdz po danych i policz potegi liczby 3
for x in data:
    count += is_power_of(x, 3)

# zapisz odpowiedz
answer = f'4.1. Ilosc liczb ktore sa potegami liczby 3: {count}'
print(answer)
