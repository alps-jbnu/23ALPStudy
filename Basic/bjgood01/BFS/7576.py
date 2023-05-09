import sys
from collections import deque
m,n = map(int, input().split())
graph = []
queue = deque()  # 큐 구현을 위해 덱 이용
for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().rstrip().split())))

for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:  # 익은 토마토라면 큐에 저장한다
            queue.append((i,j))

# 움직일수 있는 방향
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# 큐가 빌때까지 반복한다
while queue:
    # 큐에 있는 맨앞좌표를 빼낸다
    x,y = queue.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        # 움직인 위치가 공간을 벗어났으면 무시
        if nx < 0 or ny < 0 or nx >= n or ny >= m:
            continue

        if graph[nx][ny] == 0:  # 토마토가 익지 않은곳 이라면
            graph[nx][ny] = graph[x][y] + 1 # 안익은 곳을 익게 한다
            queue.append((nx,ny))  # 움직인 곳을 다시 큐에 삽입

count = 0
for line in graph:
    for tomato in line:
        if tomato == 0:   # 안익은 토마토(0)이 있으면
            # 토마토가 모두 익지 못하므로 -1 출력하고 종료
            print(-1)
            exit()
    count = max(count, max(line))  # 행마다 가장 큰것을 찾기 위함

print(count-1)   # 처음에 시작을 익은토마토(1)에서 시작했으므로 1을 빼준다
