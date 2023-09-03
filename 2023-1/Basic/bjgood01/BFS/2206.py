from collections import deque
import sys
# 중간에 벽을 한번 부술수 있기에 벽을 부쉈는지의 여부를 3차원 행렬로 나타낸다
# visited[x][y][0] 은 안부순 경로, visited[x][y][1]은 부순 경로
# 벽을 부순 경로는 그 이후의 경로부터 벽을 지나갈수 없으므로 벽이 아닌곳들만 탐색하고, 중간에 벽을 부수지 않은 경로는
# 그 이후의 경로에서 벽을 부술수 있는 선택권이 주어진다
n,m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int,sys.stdin.readline().rstrip())))

# 3차원 행렬을 통해 벽의 파괴를 파악, visited[x][y][0]은 벽파괴 가능, [x][y][1]은 벽파괴 불가능
visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]
visited[0][0][0] = 1  # 시작부분을 1로 시작한다고 가정
# 움직일수 있는 4방향
dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bfs(x,y,z):
    queue = deque()
    queue.append((x,y,z))
    while queue:
        x,y,z = queue.popleft()
        # 끝점에 도달하면 이동 횟수를 출력
        if x == n-1 and y == m-1:
            return visited[x][y][z]
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            # 다음 이동할 곳이 벽이고, 벽 파괴를 사용하지 않은경우
            if graph[nx][ny] == 1 and z == 0:
                visited[nx][ny][1] = visited[x][y][0] + 1  # 벽파괴 사용하므로 1로 바뀜
                queue.append((nx, ny, 1))
            # 다음 이동할 곳이 벽이 아니고, 아직 한번도 방문 안한곳이라면
            elif graph[nx][ny] == 0 and visited[nx][ny][z] == 0:
                visited[nx][ny][z] = visited[x][y][z] + 1
                queue.append((nx, ny, z))

    return -1
print(bfs(0, 0, 0))
