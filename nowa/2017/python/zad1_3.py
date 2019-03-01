with open('../dane/dane.txt') as f:
    dane = [x[:-1].split(' ') for x in f]

kontrastujace_piksele = 0
sasiedzi = [
    (1, 0),
    (0, 1),
    (-1, 0),
    (0, -1)
]
for x in range(len(dane)):
    for y in range(len(dane[x])):
        for px, py in sasiedzi:
            if 0 > x + px or x + px >= len(dane) or 0 > y + py or y + py >= len(dane[x]):
                pass
            elif abs(int(dane[x][y]) - int(dane[x + px][y + py])) > 128:
                kontrastujace_piksele += 1
                break


odpowiedz = f'6.3) Jest {kontrastujace_piksele} kontrastujacych pikseli'
print(odpowiedz)
