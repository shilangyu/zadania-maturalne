import zad4_1
import zad4_2
import zad4_3

result = '\n'.join([zad4_1.answer, zad4_2.answer, zad4_3.answer])
with open('wyniki.txt', mode='w') as f:
    f.write(result)
