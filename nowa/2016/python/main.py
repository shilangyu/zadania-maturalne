import zad6_1
import zad6_2
import zad6_3

# zebranie odpowiedzi z podpunktow i zapisanie ich do pliku
result = '\n'.join([zad6_1.answer, zad6_2.answer,
                    zad6_3.answer])
with open('wyniki.txt', mode='w') as f:
    f.write(result)
