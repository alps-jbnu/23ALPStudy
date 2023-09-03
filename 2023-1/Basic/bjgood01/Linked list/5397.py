import sys
# 스택 2개 확용

# 문자열이 들어오면 왼쪽 스택에 넣고, 
# < 라면, stack_l 의 마지막 값을 pop()하여 stack_r에 append하고,
# > 라면, stack_r 의 마지막 값을 pop()하여 stack_l에 append 해준다
# '-'라면, stack_l의 마지막 값을 지운다
n = int(input())
for i in range(n):
    stack_l = []  # 왼쪽 스택
    stack_r = []  # 오른쪽 스택
    string = sys.stdin.readline().strip()

    for item in string:
        if item == '<' and stack_l: # 왼쪽 스택에 값이 있어야 커서가 움직인다
            stack_r.append(stack_l.pop())
        elif item == '>' and stack_r:  # 오른쪽 스택에 값이 있어야 커서가 움직인다
            stack_l.append(stack_r.pop())   
        elif item == '-' and stack_l:   # 백스페이스는 왼쪽 스택에서 값 제거
            stack_l.pop()
        else:  # 문자열들은 왼쪽 스택에 넣는다
            stack_l.append(item)
    # 왼쪽 스택과 오른쪽 스택을 합쳐줘야한다
    stack_l.extend(reversed(stack_r))  # 오른쪽 스택은 반대정렬이므로 reversed 해주고 왼쪽 스택뒤에 확장한다
    # join메서드를 이용해 리스트를 문자열로 변환
    print(''.join(stack_l))
