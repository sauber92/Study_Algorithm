# Baekjoon Online Judge Q)1874
# Language : python3
# Version : 3.5.2
# Date : 2017. 03. 07
# Junyoung Jung(@sauber92)
loop = int(input())
stack = []
# result = []

for i in range(1, loop + 1):
    print(i)
    value = int(input())

    for i in range(value):
        stack.append(i)
        print(stack.pop())