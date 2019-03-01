import zad1_1
import zad1_2
import zad1_3
import zad1_4


wyniki = '\n'.join([zad1_1.odpowiedz, zad1_2.odpowiedz,
                    zad1_3.odpowiedz, zad1_4.odpowiedz])
with open('wyniki.txt', mode='w') as f:
    f.write(wyniki)
