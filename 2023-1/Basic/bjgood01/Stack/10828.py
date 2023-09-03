import sys
n = int(input())
stack = []
for i in range(n):
    s = sys.stdin.readline().strip()
    if 'push' in s:
        a = s.split()
        stack.append(a[1])
    elif 'pop' in s:
        if len(stack) != 0:  # 스택에 값이 없으면
            print(stack.pop())
        else:
            print(-1)
    elif 'empty' in s:
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif 'size' in s:
        print(len(stack))
    elif 'top' in s:
        if len(stack) != 0:
            print(stack[-1])
        else:
            print(-1)
