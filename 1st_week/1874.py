# Baekjoon Online Judge Q)1874
# Language : python3
# Version : 3.5.2
# Date : 2017. 03. 07
# Junyoung Jung(@sauber92)
# Reference : http://qkqhxla1.tistory.com/652

loop = int(input())
stack = []
result = ''
index = 1
flag = True

for i in range(loop):
    value = int(input())

    if value > loop or (len(stack) > 0 and stack[-1] > value):
        flag = False
        break

    while True:
        if index > value:
            break

        stack.append(index)
        result += '+\n'
        index += 1

    stack.pop()
    result += '-\n'

if flag:
    print(result[:-1])
else:
    print('NO')