# wczytanie napisow
with open('../dane/gra.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# funkcja zwraca liczbe zywych sasiadow
def alive_n(x, y):
    amount = 0
    for i in (-1, 0, 1):
        for j in (-1, 0, 1):
            currx = x + i
            curry = y + j
            # pominiecie siebie
            if i == 0 and j == 0:
                continue
            # zawiniecie
            if currx >= len(data):
                currx = 0
            if curry >= len(data[0]):
                curry = 0
            # sprawdzenie czy zywe
            if data[currx][curry] == 'X':
                amount += 1

    return amount


# wykonanie 36 pokolen
for x in range(2, 38):
    next_gen = []

    # przejscie po kazdej komorce
    for i in range(len(data)):
        next_gen.append('')
        for j in range(len(data[i])):
            is_alive = data[i][j] == 'X'
            alive_buddies = alive_n(i, j)
            # zastosowanie metod przezycia
            if is_alive and (alive_buddies == 2 or alive_buddies == 3):
                next_gen[-1] += 'X'
            elif not is_alive and alive_buddies == 3:
                next_gen[-1] += 'X'
            else:
                next_gen[-1] += '.'

    data = next_gen


# wyswietlenie odpowiedzi
answer = f'5.1. Liczba sasiadow dla komorki w drugim wierszu i dziewietnastej kolumnie w trzydziestym siodmym pokoleniu: {alive_n(1, 18)}'
print(answer)
