import zad5_a
import zad5_b
import zad5_c

# zebranie odpowiedzi z podpunktow i zapisanie ich do pliku
result = '\n'.join([zad5_a.answer, zad5_b.answer, zad5_c.answer])
with open('wyniki.txt', mode='w') as f:
    f.write(result)
