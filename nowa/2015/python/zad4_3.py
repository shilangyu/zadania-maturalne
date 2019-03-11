# ladowanie danych
with open('../dane/liczby.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1])

# szukanie max i min
biggest_number = '0'
biggest_number_row = -1
smallest_number = '1' * 1000
smallest_number_row = -1
for i, line in enumerate(data):
    if len(line) > len(biggest_number):
        biggest_number = line
        biggest_number_row = i + 1
    elif len(line) == len(biggest_number):
        for bst, cur in zip(biggest_number, line):
            if cur == '1' and bst != '1':
                biggest_number = line
                biggest_number_row = i + 1
                break
            elif cur != '1' and bst == '1':
                break

    if len(line) < len(smallest_number):
        smallest_number = line
        smallest_number_row = i + 1
    elif len(line) == len(smallest_number):
        for sml, cur in zip(smallest_number, line):
            if cur == '0' and sml != '0':
                smallest_number = line
                smallest_number_row = i + 1
                break
            elif cur != '0' and sml == '0':
                break

# zapisanie odpowiedzi
answer = f'4.3. Najwieksza liczba znajduje sie w wierszu: {biggest_number_row}; Najmniejsza liczba znajduje sie w wierszu: {smallest_number_row}'
print(answer)
