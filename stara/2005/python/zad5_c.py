# wczytanie wszystkich trzech plikow
with open('../dane/dane5-1.txt') as f:
    data1 = []
    for line in f.readlines():
        data1.append(line[:-1])
with open('../dane/dane5-2.txt') as f:
    data2 = []
    for line in f.readlines():
        data2.append(line[:-1])
with open('../dane/dane5-3.txt') as f:
    data3 = []
    for line in f.readlines():
        data3.append(line[:-1])


# zwraca najpopularnieszy element
def most_common(data):
    # slownik zawierajacy licznik wystapien
    counter = {}
    for element in data:
        # jezeli istnieje w slowniku dodaj jeden, inaczej stworz z wartoscia jeden
        if element in counter:
            counter[element] += 1
        else:
            counter[element] = 1

    # znalezienie najwiekszego licznika
    best = data[0]
    for key in counter:
        if counter[key] > counter[best]:
            best = key

    return best


rec1 = most_common(data1)
rec2 = most_common(data2)
rec3 = most_common(data3)


# wyswietlenie odpowiedzi
answer = f'5 c) Najpopularnieszy element dla dane5-1.txt: {rec1}; '
answer += f'Najpopularnieszy element dla dane5-2.txt: {rec2}; '
answer += f'Najpopularnieszy element dla dane5-3.txt: {rec3}'
print(answer)
