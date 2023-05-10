# 파이썬은 재귀 제한이 걸려있기 때문에 재귀 허용치가 넘어가면 런타임 에러가 발생한다
# 따라서 허용 범위를 넓혀 준다
import sys
sys.setrecursionlimit(100000) # 재귀 최대 깊이

n,m = map(int,input().split())  # n은 정점의 개수, m은 간선의 개수
graph = [[i] for i in range(n+1)]   # graph = [[0], [1], [2], [3],.... [n]] 있을것이다

for i in range(m):
    a,b = map(int, sys.stdin.readline().rstrip().split())
    # 무방향 그래프다 보니 양 정점에 표시를 해준다
    graph[a].append(b)
    graph[b].append(a)
visited = [False] * (n+1)   # 방문표시 배열(n개의 정점)
count = 0  # 연결요소 개수

# dfs
def dfs(graph, v, visited):
    visited[v] = True   # 시작 정점 방문표시 해준다
    for i in graph[v]:
        if not visited[i]:  # 방문하지 않은 정점이라면
            dfs(graph, i, visited)   # 해당 정점을 시작으로 다시 dfs(깊이 우선 탐색)

for i in range(1, n+1):  # 정점은 1부터 시작
    if not visited[i]:   # 방문하지 않은 노드라면
        count += 1       # 연결요소 증가
        dfs(graph, i, visited)  # dfs 탐색

print (count)
