with open('../dane/dane.txt') as f:
    data = []
    for line in f.readlines():
        data.append(line[:-1].split(' '))


def is_palindrome(line):
    return line == [*reversed(line)]


not_pali = 0
for ln in data:
    if not is_palindrome(ln):
        not_pali += 1

answer = f'6.2) Trzeba usunac {not_pali} wierszy'
print(answer)
