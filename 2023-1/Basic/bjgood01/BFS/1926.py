from collections import deque
import sys
# 모든 부분을 탐색해야되기 때문에 bfs로 푼다
# 1로 이어져 있는 부분은 count로 카운트 해주고, paint 배열에 append 해준다
n,m = map(int, input().split())
graph = []
for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().rstrip().split())))

# 이동할 4가지 방향
dx = [0,0,1,-1]
dy = [1,-1,0,0]

def bfs(graph, x, y):
    # 큐 구현을 위해 덱 사용
    queue = deque()
    # 시작 노드를 튜플 형태로 대입
    queue.append((x,y))
    # 해당 시작 노드 방문 처리를 바로 해준다
    graph[x][y] = 0
    count = 1

    # 큐가 빌때 까지 반복
    while queue:
        # 큐에서 노드를 하나 꺼낸다
        x,y = queue.popleft()
        # 4가지 방향 이동 확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 움직인 위치가 공간을 벗어나면 무시 
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            # 해당 노드를 처음 방문한다면
            if graph[nx][ny] == 1:
                graph[nx][ny] = 0  # 움직인 곳은 0으로 방문처리 해준다, 그리고 큐에 넣어준다
                queue.append((nx,ny))
                count += 1   # 그림으 면적이 증가

    # 큐가 빈다는 것은, 더이상 이동할 곳이 없으므로, 면적 반환
    return count
