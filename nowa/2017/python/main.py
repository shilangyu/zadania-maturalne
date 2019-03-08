import zad1_1
import zad1_2
import zad1_3
import zad1_4

# zebranie odpowiedzi z podpunktow i zapisanie ich do pliku
result = '\n'.join([zad1_1.answer, zad1_2.answer,
                    zad1_3.answer, zad1_4.answer])
with open('wyniki.txt', mode='w') as f:
    f.write(result)
