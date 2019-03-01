with open('../dane/dane.txt') as f:
    dane = [x[:-1].split(' ') for x in f]

najdluzszy_ciag = 0
aktualny_ciag = ''
aktualna_dlugosc = 0
for y in range(len(dane[0])):
    aktualny_ciag = dane[0][y]
    for x in range(len(dane)):
        if aktualny_ciag == dane[x][y]:
            aktualna_dlugosc += 1
        else:
            if aktualna_dlugosc > najdluzszy_ciag:
                najdluzszy_ciag = aktualna_dlugosc

            aktualny_ciag = dane[x][y]
            aktualna_dlugosc = 0

odpowiedz = f'6.4) Najdluzy ciag tych samych pikseli w kolumnie to {najdluzszy_ciag}'
print(odpowiedz)
