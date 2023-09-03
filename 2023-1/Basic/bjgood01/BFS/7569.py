import sys
from collections import deque
m,n,h = map(int, input().split())
queue = deque()
# 3차원 리스트 생성
graph = [[list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(n)] for _ in range(h)]
# 방문 배열
visited = [[[False] * m for _ in range(n)] for _ in range(h)]
day = 0
# 6방향
dx = [1,-1,0,0,0,0]
dy = [0,0,1,-1,0,0]
dz = [0,0,0,0,1,-1]

def bfs():
    while queue:  # 큐가 빌때까지 반복
        x,y,z = queue.popleft()
        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]

            if nx < 0 or ny < 0 or nz < 0 or nx >= h or ny >= n or nz >= m:
                continue

            if graph[nx][ny][nz] == 0 and visited[nx][ny][nz] == False:
                queue.append((nx,ny,nz))
                visited[nx][ny][nz] = True
                graph[nx][ny][nz] = graph[x][y][z] + 1


# 1을 값으로 가지고 있는 토마토의 위치를 배열에 담아준다
for a in range(h):
    for b in range(n):
        for c in range(m):
            if graph[a][b][c] == 1 and visited[a][b][c] == False:  # 익은토마토이고, 방문한적 없다면
                visited[a][b][c] = True
                queue.append((a,b,c))

bfs()

# 토마토 확인
for a in graph:
    for b in a:
        for c in b:
            if c == 0:  # 아직 리스트에 0이 있다는 것은 모두 익지 못했다는 것이므로 -1 출력
                print(-1)
                exit()

        day = max(day, max(b))

print(day-1)
