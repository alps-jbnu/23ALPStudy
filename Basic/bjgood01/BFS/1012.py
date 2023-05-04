from collections import deque
import sys
T = int(input())   # 테스트 케이스의 개수
# 움직일수 있는 방향
dx = [1,-1,0,0]
dy = [0,0,1,-1]

def bfs(graph, x, y):
    # 큐 구현을 위해 덱 사용
    queue = deque()
    # 시작 노드를 튜플 형태로 대입
    queue.append((x,y))
    # 해당노드 방문처리
    graph[x][y] = 0 
  
    # 큐가 빌때까지 반복
    while queue:
        # 큐에서 노드를 하나 꺼낸다
        x,y = queue.popleft()
        # 4가지 방향 확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
           
            # 노드 확인
            if 0 <= nx < m and 0 <= ny < n and graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx,ny))
               


for _ in range(T):
    count  = 0
    m, n, k = map(int, sys.stdin.readline().rstrip().split())
    # 초기에 전부 0으로 되어 있음
    graph = [[0] * n for _ in range(m)]  

    # 배추 위치 입력
    for i in range(k):
        x,y = map(int, sys.stdin.readline().rstrip().split())
        graph[x][y] = 1 # 그 위치에 배추가 있다

    for i in range(m):
        for j in range(n):
            if graph[i][j] == 1: # 배추가 심어져 있는 땅
                bfs(graph,i,j)
                count += 1   # 배추가 심어져 있는곳을 찾으면 count를 증가시켜 준다

    print(count)
