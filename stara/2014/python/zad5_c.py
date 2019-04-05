# wczytanie napisow
with open('../dane/NAPIS.TXT') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])


# zbior slow powtarzajacych
repetitions = []
# zbior slow po drodze
words = []
# przejscie po slowach
for word in data:
    # jezeli jest w 'bylych' slowach i nie jest juz zapisany to zapisz jako powtorka
    if word not in repetitions and word in words:
        repetitions.append(word)
    words.append(word)


# wyswietlenie odpowiedzi
nl = '\n'
answer = f'5 c) Powtarzajace sie slowa: {nl}{nl.join(repetitions)}'
print(answer)
