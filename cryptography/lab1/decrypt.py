print('Enter a key: ')
key = int(input())
table = []
print('Enter a ciphertext: ')
text = input()
key2 = len(text)//key+1
mv = key - (key * key2 - len(text))
for i in range(key):
    table.append(['']*key2)
    if i < mv:
        for j in range(key2):
            table[i][j] = (text[i * key2 + j])
    else:
        for j in range(key2 - 1):
            table[i][j] = (text[(mv) * key2 + (i - mv) * (key2 - 1) + j])
for i in range(key2):
    for j in range(key):
        print(table[j][i], end = '')
