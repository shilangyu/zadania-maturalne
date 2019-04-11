# jezeli liczba jest podzielna przez liczby inne niz {1, n} to nie jest liczba pierwsza
def isprime(n):
    if n == 1:
        return False
    for i in range(2, n//2 + 1):
        if n % i == 0:
            return False

    return True


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


# zliczenie ilosci liczb gdzie suma cyfr w przedziale <100,10000> jest liczba pierwsza
amount_of_primes = 0
for num in range(100, 10001):
    if isprime(digitsum(num)):
        amount_of_primes += 1

# zliczenie sumy cyfr super B pierwszych w przedziale <100,1000>
superBprime_sum = 0
for num in superBprime(100, 10001):
    superBprime_sum += int(num)
# sprawdzenie czy suma jest pierwsza
sum_is_prime = isprime(superBprime_sum)


# wyswietlenie odpowiedzi
answer = f'5 b) Ilosc liczb z przedzialu <100,10000> gdzie suma cyfr jest liczba pierwsza: {amount_of_primes}; Suma wszystkich liczb super B pierwszych z przedzialu <100,10000> jest liczba pierwsza: {sum_is_prime}'
print(answer)
