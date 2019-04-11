# wczytanie slow
with open('../dane/dane.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1])


# slownik zawierajacy wszystkie slowa i ich ilosc
words = {}
for word in data:
    # jezeli jest juz zapisane dodaj jeden do licznika, inczej stworz z licznikiem 1
    if word in words:
        words[word] += 1
    else:
        words[word] = 1

# licznik powtarzajacyh sie slow
repeats = 0
# najczestsze slowo
most_common = data[0]

for word in words:
    # jezeli jest licznik wskazuje wiecej niz jeden zlicz
    if words[word] > 1:
        repeats += 1
    # jezeli pobilo rekord zapisz
    if words[most_common] < words[word]:
        most_common = word


# wyswietlenie odpowiedzi
answer = f'6 a) Ilosc slow wystepujacych wiecej niz raz: {repeats}; Slowo o najwiekszej liczbie wystapien: {most_common}; Wystapil tyle razy: {words[most_common]}'
print(answer)
