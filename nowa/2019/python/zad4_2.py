from math import factorial

# zaladuj dane
data = [x[:-1] for x in open('../dane/liczby.txt')]


def factorial_sum(num):
    """zsumuj silnie kazdego ze znakow liczby"""

    processed = []
    # podziel liczbe na liste znakow
    for x in list(num):
        # dodaj do `processed` silnie kazdego ze znakow
        processed.append(factorial(int(x)))
    return sum(processed)


numbers = []

# przejdz po numerach i sprawdz ktore sumy silni sie rownaja silni samej liczby
for x in data:
    if int(x) == factorial_sum(x):
        numbers.append(x)

# zapisz odpowiedz
final_nums = '\n'.join(numbers)
answer = f'4.2. liczby rowne sumie silni swoich liczb: \n{final_nums}'
print(answer)
