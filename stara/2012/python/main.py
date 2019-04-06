import zad4_a
import zad4_b

# zebranie odpowiedzi z podpunktow i zapisanie ich do pliku
result = '\n'.join([zad4_a.answer, zad4_b.answer])
with open('wyniki.txt', mode='w') as f:
    f.write(result)
