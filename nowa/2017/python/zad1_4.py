with open('../dane/dane.txt') as f:
    for line in f.readlines():
        data = line[:-1].split(' ')

longest = 0
current = ''
curr_len = 0
for y in range(len(data[0])):
    current = data[0][y]
    for x in range(len(data)):
        if current == data[x][y]:
            curr_len += 1
        else:
            if curr_len > longest:
                longest = curr_len

            current = data[x][y]
            curr_len = 0

answer = f'6.4) Najdluzy ciag tych samych pikseli w kolumnie to {longest}'
print(answer)
