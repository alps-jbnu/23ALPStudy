from collections import deque
import sys
n = int(sys.stdin.readline().rstrip())
for i in range(n):
    s = list(input())
    numbers = int(sys.stdin.readline().rstrip())
    arr = input()[1:-1].split(',')   # 대괄호와 ,를 제거하고 큐에 담는다
    queue = deque(arr)
    flag = 0   # R이 홀수개이면, 뒤집고, R이 짝수개이면 그대로이다


    # deque이 ['']의 길이를 1로 취급하기때문에 초기화 필요
    if numbers == 0:
        queue = []
    
    for item in s:
        if item == 'R':
            flag += 1
            # R의 개수가 홀수일경우에만 reverse 이용한다
        elif item == 'D':
            if len(queue) == 0:
                print('error')
                break
            else:
                if flag % 2 == 1:
                    queue.pop()
                else:
                    queue.popleft()

    else:
        if flag %2 == 1:  # flag가 홀수개이면
            queue.reverse()
           
        print('[' + ','.join(queue) + ']')
