# zaladuj dane
data = [(int(x.split()[0]), x.split()[1])
        for x in open('../dane/pary.txt')]


def longest_rep(line):
    """zwraca najdluzszy podciag z identycznych liter"""

    best_c = None
    best_n = 0
    curr = 0

    for c1, c2 in zip(line, [*line[1:], None]):
        if c1 == c2:
            curr += 1
        else:
            curr = 1

        if best_n < curr:
            best_n = curr
            best_c = c1

    return best_c * best_n


results = []

# przejdz po danych
for _, line in data:
    # zapisz znaleziony ciag
    results.append(longest_rep(line))

# zapisz odpowiedz
formatted = '\n'.join(f'{x} {len(x)}' for x in results)
answer = f'4.2: \n{formatted}'
print(answer)
