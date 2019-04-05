import zad6_a
import zad6_b
import zad6_c

# zebranie odpowiedzi z podpunktow i zapisanie ich do pliku
result = '\n'.join([zad6_a.answer, zad6_b.answer, zad6_c.answer])
with open('wyniki.txt', mode='w') as f:
    f.write(result)
