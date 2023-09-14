import sys
stack_l = list(input())   # 스택 왼쪽 표현
stack_r = []              # 스택 오른쪽 표현
n = int(input())
for i in range(n):
    command = sys.stdin.readline().split()    # 반복문에서는 sys가 더 단축된다
    # L이나오면 커서가 왼쪽으로 한칸이동한다, L이고, 왼쪽 스택에 값이 있으면
    # stack_l의 마지막값을 pop해서, stack_r의 맨뒤에 append
    if command[0] == 'L' and stack_l:       
        stack_r.append(stack_l.pop())
    # D가나오면 커서가 오른쪽으로 한칸이동, R이고, 오른쪽 스택에 값이 있으면
    # stack_r의 마지막값을 pop해서, stack_l의 맨뒤에 append
    elif command[0] == 'D' and stack_r:
        stack_l.append(stack_r.pop())
    # B가나오면 커서왼쪽값 삭제, B이고, 왼쪽 스택에 값이 있으면
    # stack_l의 마지막값 pop해준다
    elif command[0] == 'B'and stack_l:
        stack_l.pop()
    # P가나오면 커서 왼쪽에 값 추가, split()으로 받았으니 command[1]값을
    # 왼쪽 스택에 append 해준다
    elif command[0] == 'P':
        stack_l.append(command[1])


# 오른쪽 스택을 reversed 해주고 왼쪽 스택에 확장해준다
stack_l.extend(reversed(stack_r))
# join메서드를 이용해 리스트를 문자열로 변환
print(''.join(stack_l))
