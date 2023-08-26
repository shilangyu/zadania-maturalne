# zaladuj dane
data = [(int(x.split()[0]), x.split()[1])
        for x in open('../dane/pary.txt')]


def is_of_length(pair):
    """sprawdza dlugosc line jest rowna x"""
    return len(pair[1]) == pair[0]


def is_smaller_than(pair1, pair2):
    """sprawdza pair1 jest mniejsze od pair2"""
    if pair1[0] < pair2[0]:
        return True
    if pair1[0] > pair2[0]:
        return False

    # tutaj, pair1[0] == pair2[0]
    return pair1[1] < pair2[1]


result = None

# wez tylko te pary ktore spelniaja warunek
to_consider = list(filter(is_of_length, data))


# znajdz pare mniejsza od wszystkich innych
for i, pair1 in enumerate(to_consider):
    is_smaller = True
    for j, pair2 in enumerate(to_consider):
        if i == j:
            break
        if not is_smaller_than(pair1, pair2):
            is_smaller = False

    # jest mniejsza od wszystkich innych, zapisz
    if is_smaller:
        result = pair1


# zapisz odpowiedz
formatted = ' '.join(map(str, result))
answer = f'4.1: {formatted}'
print(answer)
