data = [int(x[:-1]) for x in open('../dane/liczby.txt')]


def is_power_of(x, n):
    """checks if `x` is the power of `n`"""
    if x == 1:
        return True
    if x % n != 0:
        return False
    while x >= n:
        if x == n:
            return True
        x /= n
    return False


count = 0


for x in data:
    count += is_power_of(x, 3)


answer = f'4.1. Ilosc liczb ktore sa potegami liczby 3: {count}'
