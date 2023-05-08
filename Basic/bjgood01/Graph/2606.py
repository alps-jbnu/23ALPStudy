import sys
sys.setrecursionlimit(100000)  # 재귀 최대깊이

n = int(input())  # 컴퓨터의수(정점의 개수)
m = int(input())  # 간선의 개수
graph = [[i] for i in range(n+1)]  # 0~7까지 있는데, 1~7만 사용
visited = [False] * (n+1)          # 방문 표시 배열
count = 0
for i in range(m):
    a,b = map(int, sys.stdin.readline().rstrip().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(graph, v, visited):
    global count   # count를 전역 변수로 설정
    visited[v] = True  # 시작 정점 방문표시
    for i in graph[v]:
        if not visited[i]:
            count += 1
            dfs(graph, i, visited)

dfs(graph, 1, visited)
print(count)
