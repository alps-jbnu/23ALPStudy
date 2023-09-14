import sys
from collections import deque

n,m = map(int, input().split())
graph = [[] for _ in range(n+1)]

def bfs(start, find):  # 시작노드, 찾는노드
    # 큐를 생성하고, 시작노드와 거리는 0으로 초기화한다
    queue = deque()
    queue.append((start, 0))
    # 여러번의 테스트 케이스를 위해 visited는 bfs안에서 생성
    visited = [False] * (n+1)
    visited[start] = True
    while queue:
        v,d = queue.popleft()  # popleft로 현재노드 v와 start로부터 현재노드 v까지 거리 d를 가져온다

        if v == find: # 현재노드 v가 찾는노드일 경우 d를 return
            return d
        for i, l in graph[v]:  # graph에는 (노드번호, 간선길이)가 들어있다
            if not visited[i]:
                # 방문하지 않은 노드일 경우 방문처리해주고, queue에 (연관된 노드번호 i, 지금까지의 거리)를 기록해준다
                visited[i] = True
                queue.append((i, d+l))


for _ in range(n-1):
    n1, n2, l = map(int, sys.stdin.readline().rstrip().split()) # n1,n2는 노드번호, l은 간선의 길이
    # 그래프에 추가할때 (노드번호, 간선의 길이)형태로 추가한다
    graph[n1].append((n2, l))
    graph[n2].append((n1, l))

for _ in range(m):
    # 찾고자하는 두 노드를 입력받고 bfs 함수에 두 노드번호를 매개변수로 전달해 return 받은 노드사이의 거리를 출력
    a,b = map(int, sys.stdin.readline().rstrip().split())
    print(bfs(a,b))
