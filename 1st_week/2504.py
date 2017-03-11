# Baekjoon Online Judge Q)1874
# Language : python3
# Version : 3.5.2
# Date : 2017. 03. 11
# Junyoung Jung(@sauber92)
# Reference: http://qkqhxla1.tistory.com/645

dic = {'(':')', '[':']'}
stack = []
bracket = input()
flag = True

for i in range(len(bracket)):
    if bracket[i] in ['(', '[']:
        stack.append(bracket[i])

    else:
        try:
            pop = stack.pop()
        except:
            print(0)
            flag = False
            break

        temp = 0
        while pop != '(' and pop != '[':
            temp += pop
            pop = stack.pop()

        if bracket[i] == dic[pop]:
            if bracket[i] == ')':
                if temp == 0:
                    stack.append(2)
                else:
                    stack.append(2 * temp)

            else:
                if temp == 0:
                    stack.append(3)
                else:
                    stack.append(3 * temp)

        else:
            print(0)
            flag = False
            break

if flag:
    try:
        print(sum(stack))
    except:
        print(0)