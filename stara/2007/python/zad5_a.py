# jezeli liczba jest podzielna przez liczby inne niz {1, n} to nie jest liczba pierwsza
def isprime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True

    if n % 2 == 0 or n % 3 == 0:
        return False

    for i in range(5, n + 6, 6):
        if i * i > n:
            return True
        if n % i == 0 or n % (i + 2) == 0:
            return False



# sumowanie cyfr
def digitsum(n):
    result = 0
    for digit in str(n):
        result += int(digit)

    return result


# zapisuje wszystkie super B pierwszye w danym przedziale gdzie [start, end)
def superBprime(start, end):
    nums = []

    for num in range(start, end):
        # czy jest pierwsza? czy suma cyfr jest pierwsza? czy suma cyfr reprezentacji binarnej jest pierwsza?
        if isprime(num) and isprime(digitsum(num)) and isprime(digitsum(bin(num)[2:])):
            nums.append(str(num))

    return nums


p1 = superBprime(2, 1001)
p2 = superBprime(100, 10001)
p3 = superBprime(1000, 100001)

# wyswietlenie odpowiedzi
nl = '\n'
answer = f'5 a) Ilosc super B pierwsze w przedziale <2,1000>: {len(p1)};'
answer += f' Ilosc super B pierwsze w przedziale <100,10000>: {len(p2)};'
answer += f' Ilosc super B pierwsze w przedziale <1000,100000>: {len(p3)};' + nl
answer += f'Super B pierwsze z przedzialu <2,1000>: {nl}{nl.join(p1)};' + nl
answer += f'Super B pierwsze z przedzialu <100,10000>: {nl}{nl.join(p2)};' + nl
answer += f'Super B pierwsze z przedzialu <1000,100000>: {nl}{nl.join(p3)}'
print(answer)
