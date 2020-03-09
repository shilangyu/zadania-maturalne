data = [int(x[:-1]) for x in open('../dane/liczby.txt')]


def nwd(nums):
    smol = min(nums)

    for el in reversed(range(1, smol // 2 + 1)):
        if smol % el == 0:
            for a in nums:
                if a % el != 0:
                    break
            else:
                return el
    return 1


best = []
for a in range(len(data)):
    for b in reversed(range(a+1+len(best), len(data))):
        if nwd(data[a:b]) > 1:
            if len(best) < len(data[a:b]):
                best = data[a:b]
            break

best_nwd = nwd(best)


answer = f'4.3. Pierwsza liczba: {best[0]}; ' + \
         f'dlugosc ciagu: {len(best)}; ' + \
         f'najwiekszy dzielnik: {best_nwd}'

