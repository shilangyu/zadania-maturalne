import zad5_1
import zad5_2
import zad5_3

# zebranie odpowiedzi z podpunktow i zapisanie ich do pliku
result = '\n'.join([zad5_1.answer, zad5_2.answer,
                    zad5_3.answer])
with open('wyniki.txt', mode='w') as f:
    f.write(result)
