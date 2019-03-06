# ladowanie danych do tablicy dwu-wymiarowej
with open('../dane/dane.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1].split(' '))

# licznik pikseli kontrastujacych
contrasting_pixels = 0
# tablica (x, y) sasiadow
neighbors = [
    (1, 0),
    (0, 1),
    (-1, 0),
    (0, -1)
]
for x in range(len(data)):
    for y in range(len(data[x])):
        for px, py in neighbors:
            # jezeli jest to piksel z brzegu, omin
            if 0 > x + px or x + px >= len(data) or 0 > y + py or y + py >= len(data[x]):
                pass
            # jezeli dwa piksele maja bezwgledna roznice wieksza niz 128, policz
            elif abs(int(data[x][y]) - int(data[x + px][y + py])) > 128:
                contrasting_pixels += 1
                break


# wyswietlenie odpowiedzi
answer = f'6.3) Jest {contrasting_pixels} kontrastujacych pikseli'
print(answer)
