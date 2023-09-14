import sys
from collections import deque
n = int(sys.stdin.readline().rstrip())
queue = deque()
for i in range(n):
    s = list(sys.stdin.readline().rstrip().split())
    if s[0] == 'push_front':
        queue.insert(0, int(s[1]))  # 정수를 덱의 앞에 넣는다
    elif s[0] == 'push_back':
        queue.append(int(s[1]))
    elif s[0] == 'pop_front':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue.popleft())
    elif s[0] == 'pop_back':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue.pop())
    elif s[0] == 'size':
        print(len(queue))
    elif s[0] == 'empty':
        if len(queue) == 0:
            print(1)
        else:
            print(0)
    elif s[0] == 'front':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[0])
    elif s[0] == 'back':
        if len(queue) == 0:
            print(-1)
        else:
            print(queue[-1])
