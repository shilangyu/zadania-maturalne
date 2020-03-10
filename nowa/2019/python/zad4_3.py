# ladowanie danych
data = [int(x[:-1]) for x in open('../dane/liczby.txt')]


def nwd(nums):
    """funkcja do szukania najwiekszego wspolnego dzielnika"""

    smol = min(nums)

    # przejdz po odwróconym ciągu od 1 do najmniejszego elementu `nums`
    for el in reversed(range(1, smol // 2 + 1)):
        if smol % el == 0:
            # sprawdz czy kazdy element `nums` jest podzielny przez ten element
            for a in nums:
                if a % el != 0:
                    break
            else:
                return el
    return 1


best = []
# dwie petle przechodza po danych sprawdzajac ciagi od najwiekszego do najmniejszego
for a in range(len(data)):
    # petla sprawdza tylko ciagi wieksze od najlepszego
    for b in reversed(range(a+1+len(best), len(data))):
        if nwd(data[a:b]) > 1:
            if len(best) < len(data[a:b]):
                best = data[a:b]
            break

best_nwd = nwd(best)

# zapisz odpowiedz
answer = f'4.3. Pierwsza liczba: {best[0]}; ' + \
         f'dlugosc ciagu: {len(best)}; ' + \
         f'najwiekszy dzielnik: {best_nwd}'
print(answer)
