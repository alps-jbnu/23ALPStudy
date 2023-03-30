import sys
# 큐를 구현할때는 deque 라이브러리를 사용한다
from collections import deque
n = int(input())
queue = deque()
for i in range(n):
    input = sys.stdin.readline().strip()
    a = input.split()  # 띄어쓰기를 기준으로 나눈다
    if a[0] == 'push':
        queue.append(int(a[1]))
    elif a[0] == 'pop':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue.popleft())
    elif a[0] == 'size':
        print(len(queue))
    elif a[0] == 'empty':
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    elif a[0] == 'front':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
    elif a[0] == 'back':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])
