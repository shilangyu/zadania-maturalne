# ladowanie danych do tablicy dwu-wymiarowej
with open('../dane/dane.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1].split(' '))

# dlugosc najdluzszego ciagu
longest = 0
# aktualnie badany znak
current = ''
# aktualna dlugosc
curr_len = 0
for y in range(len(data[0])):
    current = data[0][y]
    for x in range(len(data)):
        # jezeli nastepny znak jest taki sam co aktualny badany, dodaj 1 do dlugosci
        if current == data[x][y]:
            curr_len += 1
        # jezeli nie, sprawdz czy pobil rekord i zresetuj zmienne 
        else:
            if curr_len > longest:
                longest = curr_len

            current = data[x][y]
            curr_len = 0

# wyswietlenie odpowiedzi
answer = f'6.4. Najdluzy ciag tych samych pikseli w kolumnie: {longest}'
print(answer)
