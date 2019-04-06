# wczytanie napisow
with open('../dane/binarne.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1])

# licznik
badtens = 0
# najkrotsze
shortest = '1'*32
# przejscie po kazdym napisie
for word in data:
    # przejscie po kazdym segmentcie napisu
    for i in range(len(word)//4):
        segment = word[i*4:(i+1)*4]
        # jezeli segment w dziesietnym jest wieksze niz 9 to zlicz
        if int(segment, base=2) > 9:
            badtens += 1
            # jezeli jest owy napis krotszy, zapisz
            if len(word) < len(shortest):
                shortest = word
            break


# wyswietlenie odpowiedzi
answer = f'4.2. Liczba napisow niepoprawnie zapisanych w BCD: {badtens}; Dlugosc najkrotszego takiego napisu: {len(shortest)}'
print(answer)
