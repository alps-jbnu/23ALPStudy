import sys
from collections import deque
n,k = map(int, input().split())  # (5,17)
# 5->10->9->18->17 총 4번의 계산

visited = [0 for i in range(100001)]
def bfs(v):
    # 큐 구현을 위해 deque 사용
    queue = deque([v])  # v위치에서 시작
    while queue:   # 큐가 빌때 까지 반복
        v = queue.popleft()  # 큐의 맨앞 좌표 빼낸다
        if v == k:
            return visited[v]
        else:
            for i in (v-1, v+1, 2*v):   # 3개의 식을 거친다
                if 0 <= i <= 100000:    # 점의 범위가 0 이상 10만 이하이다
                    if not visited[i]:  # 전에 방문하지 않았다면
                        visited[i] = visited[v] + 1  # 초마다 1씩 더해진다, 처음에는 visited 배열이 모두 0이다
                        queue.append(i)



print(bfs(n))  # n 위치 에서 시작 
