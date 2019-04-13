# wczytanie wszystkich trzech plikow
with open('../dane/dane5-1.txt') as f:
    data1 = []
    for line in f.readlines():
        data1.append(int(line[:-1]))
with open('../dane/dane5-2.txt') as f:
    data2 = []
    for line in f.readlines():
        data2.append(int(line[:-1]))
with open('../dane/dane5-3.txt') as f:
    data3 = []
    for line in f.readlines():
        data3.append(int(line[:-1]))


# laczy elementy obok siebie ktore maja ten sam znak
def squish(data):
    new_data = [data[0]]
    prev_sign = data[0]
    for num in data[1:]:
        # jezeli pomnozone to te z tym samym znakiem beda dawaly dodatnia liczbe
        if num * prev_sign > 0:
            new_data[-1] += num
        else:
            new_data.append(num)
            prev_sign = num

    return new_data


# zwraca najlepsza sume ciagu
def best_sum(data):
    # najlepsza suma
    rec = -float('inf')
    # przechodze po kazdym zakresie
    for start in range(len(data)):
        # aktualna suma
        curr_sum = data[start]
        for end in range(start + 1, len(data)):
            # zliczenie sumy
            curr_sum += data[end]
            # jezeli suma wieksza od rekordu to zapisz
            if curr_sum > rec:
                rec = curr_sum

    return rec


rec1 = best_sum(squish(data1))
rec2 = best_sum(squish(data2))
rec3 = best_sum(squish(data3))


# wyswietlenie odpowiedzi
answer = f'5 b) Najlepsza suma dla dane5-1.txt: {rec1}; '
answer += f'Najlepsza suma dla dane5-2.txt: {rec2}; '
answer += f'Najlepsza suma dla dane5-3.txt: {rec3}'
print(answer)
