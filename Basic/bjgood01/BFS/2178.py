import sys
# bfs 이용 => queue 이용
from collections import deque
n,m = map(int,input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().rstrip())))

# 이동할 4가지 방향
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(x, y):
    # 큐 구현을 위해 덱사용
    queue = deque()
    # 시작 노드를  대입
    queue.append((x,y))

    # 큐가 빌때까지 반복
    while queue:
        # 큐에서 맨앞 노드 꺼낸다
        x,y = queue.popleft()
        # 4가지 방향 이동확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 움직인 위치 확인
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
        
            # 해당 노드를 처음 방문한다면 이동할수 있다
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx,ny))   # 움직인곳을 큐에 넣어준다
                
    # 마지막 값에서 카운트 값 뽑기
    return graph[n-1][m-1]



print(bfs(0,0))   # (0,0) 부터 bfs 시작
