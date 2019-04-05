# wczytanie napisow
with open('../dane/dane.txt') as f:
    data = []
    for word in f.readlines():
        data.append(word[:-1].split(' '))


# zbior wygenerowanych C
Cs = []
# przejscie po slowach
for A, B in data:
    # jezeli B jest w A to C jest A
    if B in A:
        Cs.append(A)
        continue

    prefix_len = len(B)
    suffix_len = len(B)
    # policzenie dlugosci gdyby dodac jako prefix
    for i in range(len(B)):
        if A.startswith(B[i:]):
            prefix_len = i
            break
    # policzenie dlugosci gdyby dodac jako suffix
    for i in range(len(B)):
        if A.endswith(B[:i+1]):
            suffix_len = len(B) - i - 1

    # jezeli prefix bylby krotszy takie wlasnie C stworz, jak nie to jako suffix
    if prefix_len < suffix_len:
        Cs.append(B[:prefix_len] + A)
    else:
        Cs.append(A + B[len(B)-suffix_len:])


# wyswietlenie odpowiedzi
nl = '\n'
answer = f'5 d) Najkrotsze mozliwe slowa C: {nl}{nl.join(Cs)}'
print(answer)
