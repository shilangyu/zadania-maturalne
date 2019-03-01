with open('../dane/dane.txt') as f:
    dane = [x[:-1].split(' ') for x in f]

najjasnieszy = 0
najciemniejszy = 256
for linia in dane:
    for liczba in linia:
        liczba = int(liczba)
        najjasnieszy = liczba if liczba > najjasnieszy else najjasnieszy
        najciemniejszy = liczba if liczba < najciemniejszy else najciemniejszy

odpowiedz = f'6.1) Najciemniejszy: {najciemniejszy}, najjasniejszy: {najjasnieszy}'
print(odpowiedz)
