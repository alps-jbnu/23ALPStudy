import sys
n = int(input())
count = 1
stack =[]  # push, pop한걸 넣는 스택
op = []    # '+', '-'를 넣는 리스트
temp = True
for i in range(n):
    num = int(sys.stdin.readline().strip())
    
    # num이하 숫자는 스택에 append
    while count <= num:
        stack.append(count)
        op.append('+')
        count += 1
    
    # num과 스택의 맨위 수가 동일하면 pop
    if stack[-1] == num:
        stack.pop()
        op.append('-')
    else:   # 스택 수열을 만들수 없으므로
        temp = False
        break

# 스택 수열을만들수 있는지 여부에 따라 출력
if temp == False:
    print('NO')
else:
    for i in op:   # op에 있는 부호들을 하나씩 대입하여 출력
        print(i)
