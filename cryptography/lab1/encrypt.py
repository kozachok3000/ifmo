print('Enter a key: ')
key = int(input())
table = []
print('Enter a text: ')
text = input()
for i in range(len(text)//key+1):
    table.append([])
    for j in range(key):
        if(i * key + j < len(text)):  
            table[i].append(text[i * key + j])
        else:
            table[i].append('')
for j in range(key):
    for i in range(len(table)):
        print(table[i][j], end = '')
print()
for j in range(key):
    for i in range(len(table)):
        print(table[i][j], end = '')
    print()
