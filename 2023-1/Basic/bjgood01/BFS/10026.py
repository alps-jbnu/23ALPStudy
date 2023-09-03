import sys
from collections import deque
# 색약이 아닌경우 먼저 구해주고, 'R'을 'G'로 바꾼뒤 색약인 경우를 구한다
# 이때, 방문표시배열 visited 초기화 해준다

n = int(input())
graph = []
# 방문 표시 배열
visited = [[0] * n for _ in range(n)]

for i in range(n):
    graph.append(list(sys.stdin.readline().rstrip()))


dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(x,y):
    # 방문표시 해준다
    visited[x][y] = 1
    # 큐 구현을 위해 덱 사용
    queue = deque()
    queue.append((x,y))  # 큐에 삽입 해준다
    while queue:
        x,y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:   # 범위 내에 있고
                if graph[nx][ny] == graph[x][y] and not visited[nx][ny]:  # 현재 문자와 다음 문자가 동일하면서 방문하지 않았더라면  
                    visited[nx][ny] = 1   # 방문 표시 해준다
                    queue.append((nx,ny)) # 큐에 넣어 준다
# 색약 아닐때
no_color = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:   # 방문 안했으면
            bfs(i,j)
            no_color += 1
print(no_color, end=' ')


# 색약 일때
# 방문표시 배열 초기화 해준다
color = 0
visited = [[0] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if graph[i][j] == 'R':
            graph[i][j] = 'G'  # R과 G를 같게해준다

for i in range(n):
    for j in range(n):
        if not visited[i][j]:   # 방문한적 없다면
            bfs(i,j)
            color += 1
print(color)
