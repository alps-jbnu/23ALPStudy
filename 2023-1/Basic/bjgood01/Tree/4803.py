# DFS를 이용해 트리의 사이클이 존재하는 것을 찾아 제외하고 트리의 개수를 찾는다
import sys
sys.setrecursionlimit(10 ** 6)

def dfs(prev, node):
    visited[node] = True   # 방문표시 해준다
    for n in graph[node]:
        if n == prev:      # 부모 노드면 건너뛴다
            continue
        if visited[n]:     # 이미 방문한 곳이면 False
            return False
        if not dfs(node, n):   # DFS를 했는데 False이면   False를 반환
            return False
    return True




case = 0
while True:
    case += 1   # 출력할때 필요
    n,m = map(int, sys.stdin.readline().rstrip().split())  # n은 정점의 개수, m은 간선의 개수
    if n == 0 and m == 0:
        break
    graph = [[] for _ in range(n+1)]  # 이중 리스트 이용
    visited = [False] * (n+1)         # 방문 표시 배열
    for _ in range(m):
        a,b = map(int, sys.stdin.readline().rstrip().split())
        graph[a].append(b)
        graph[b].append(a)

    result = 0  # 트리의 개수
    for v in range(1, n+1):
        if not visited[v]:  # 방문하지 않은 경우에만 DFS 수행
            if dfs(0, v):
                result += 1   # 사이클이 없는 경우 트리 개수 증가

    if result == 0:
        print(f'Case {case}: No trees.')
    elif result == 1:
        print(f'Case {case}: There is one tree.')
    else:
        print(f'Case {case}: A forest of {result} trees.')
