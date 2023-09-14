import sys
from collections import deque
sys.setrecursionlimit(100000)
# n: 정점의 개수, m: 간선의 개수, v: 탐색시작 정점번호
n,m,v = map(int, input().split())  
graph = [[i] for i in range(n+1)]
visited1 = [False] * (n+1)
visited2 = [False] * (n+1)


for i in range(m):
    a,b = map(int, sys.stdin.readline().rstrip().split())
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()



# dfs
def dfs(graph, v, visited1):
    visited1[v] = True   # 시작 정점 방문표시
    print(v, end=' ')
    for i in graph[v]:
        if not visited1[i]:
            dfs(graph, i, visited1)

# bfs
def bfs(graph, start, visited2):
    queue = deque([start])  # 시작 노드를 큐에 넣어준다
    visited2[start] = True   # 시작 정점 방문표시
    while queue:        # 큐가 빌때 까지 반복
        v = queue.popleft()  # 맨앞 원소 뽑아 출력
        print(v, end= ' ')
        # 아직 방문하지 않은 인접한 원소들을 큐에 삽입
        for i in graph[v]:
            if not visited2[i]:
                visited2[i] = True
                queue.append(i)

dfs(graph, v, visited1)
print()
bfs(graph, v, visited2)
