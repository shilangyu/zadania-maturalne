with open('../dane/dane.txt') as f:
    data = [x[:-1].split(' ') for x in f]

contrasting_pixels = 0
neighbors = [
    (1, 0),
    (0, 1),
    (-1, 0),
    (0, -1)
]
for x in range(len(data)):
    for y in range(len(data[x])):
        for px, py in neighbors:
            if 0 > x + px or x + px >= len(data) or 0 > y + py or y + py >= len(data[x]):
                pass
            elif abs(int(data[x][y]) - int(data[x + px][y + py])) > 128:
                contrasting_pixels += 1
                break


answer = f'6.3) Jest {contrasting_pixels} kontrastujacych pikseli'
print(answer)
