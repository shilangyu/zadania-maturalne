data = []

# zbieranie danych z pliku do listy
with open('../dane/sygnaly.txt') as f:
    for x in f:
        data.append(x[:-1])


# funkcja sprawdzajaca czy string spelnia warunek z zadania
def is_valid(s):
    # parowanie kazdej litery z kazda litera zeby sprawdzic
    # czy ich kody ASCI sa wystarczajaco blisko siebie
    for a in s:
        for b in s:
            if distance(a, b) > 10:
                return False
    return True


# funkcja sprawdzajaca dystans miedzy dwoma literami w talblicy unicode
def distance(a, b):
    return abs(ord(a) - ord(b))


result = []

for s in data:
    if is_valid(s):
        result.append(s)


# wyswietlenie odpowiedzi
answer = f'4.3. Te wyrazy byly wystarczajaco blisko siebie na tablicy ASCII:\n' + \
    '\n'.join(result)
print(answer)
