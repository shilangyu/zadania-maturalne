# dane podane w zadaniu
data = [1, -2, 6, -5, 7, -3]

# najlepsza suma
best_sum = -float('inf')
# przechodze po kazdym zakresie
for start in range(len(data)):
    for end in range(start + 1, len(data) + 1):
        # zliczenie sumy
        curr = sum(data[start:end])
        # jezeli suma wieksza od rekordu to zapisz
        if curr > best_sum:
            best_sum = curr


# wyswietlenie odpowiedzi
answer = f'5 a) Najlepsza suma: {best_sum}'
print(answer)
