# Baekjoon Online Judge Q)1966
# Language : python3
# Version : 3.5.2
# Date : 2017. 03. 13
# Junyoung Jung(@sauber92)

# 중요도가 높은걸 먼저 인쇄
# 문서 수, 중요도 -> 몇번째로 인쇄되는지
import sys
import queue

flag = True
q = queue.PriorityQueue()

for i in range(int(input())):
    value = input().split()
    print(value[0])
    print(value[1])

    if int(value[0]) <= 0 or int(value[0]) > 100:
        flag = False
        break

    for j in range(int(value[0]) -1):
        priority = int(input())
        if j == int(value[1]):
            q.put(j)

    #q.put(value[0], value[1])


if flag:
    print("fff", q.get())
else:
    sys.exit()