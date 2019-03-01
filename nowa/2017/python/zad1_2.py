with open('../dane/dane.txt') as f:
    dane = [x[:-1].split(' ') for x in f]


def jest_palindromem(linia):
    return linia == [*reversed(linia)]


zle_linie = 0
for linia in dane:
    if not jest_palindromem(linia):
        zle_linie += 1

odpowiedz = f'6.2) Trzeba usunac {zle_linie} wierszy'
print(odpowiedz)
