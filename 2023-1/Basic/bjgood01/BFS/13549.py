# 순간인동은 0초가 걸리고 걷기는 1초가 걸리므로 양방향 큐인 deque을 활용한다
# 순간이동하는 경우는 appendleft로 맨앞에 추가해주고, 걷는 경우는 append로 뒤에 추가해준다
import sys
from collections import deque
n,k = map(int, input().split())
visited = [0] * 100001   # 방문 표시
queue = deque()
queue.append(n)  # 수빈이 부터 시작
visited[n] = 1
while queue:
    v = queue.popleft()
    if v == k:
        print(visited[k] - 1)   # 초기에 수빈이 시작할때 visited[n]에 1을 넣고 시작했으므로, 출력할때 하나빼고 출력해준다
        break
    for next in (2*v, v-1, v+1):
        if 0 <= next < 100001 and visited[next] == 0:
            if next == 2 * v:  # 순간이동하는 경우
                visited[next] = visited[v]
                queue.appendleft(next)
            else:
                visited[next] = visited[v] + 1
                queue.append(next)
