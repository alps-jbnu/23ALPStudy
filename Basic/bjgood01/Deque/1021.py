from collections import deque
n, m = map(int, input().split())
pick = list(map(int, input().split()))
queue = deque(i for i in range(1, n+1))  # 1~n까지 들어있는 큐 생성
count = 0

for i in pick:
    while True:
        if queue[0] == i:  # 찾고자하는 수와 같다면
            queue.popleft()
            break
        elif queue.index(i) < len(queue) / 2:   # 찾고 싶은 값이 앞쪽에 있으면 앞쪽을 pop해주고 뒤로 보낸다
            while queue[0] != i:      # 찾는 값과 다르다면
                queue.append(queue.popleft())
                count += 1
        else:  # 찾고 싶은 값이 뒤쪽에 있으면 뒤쪽을 pop해서 앞쪽에 append 해준다
            while queue[0] != i:  # 찾는 값과 다르다면
                queue.appendleft(queue.pop())
                count += 1

print(count)

