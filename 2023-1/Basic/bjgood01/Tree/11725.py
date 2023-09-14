import sys
# DFS 방식
# 루트인 1부터 dfs 탐색을 하고, 1과 연결되어 있는 node들중 방문하지 않은 노드를 방문하는데, 이때 visited 배열의
# index에 부모노드를 저장한다. 이렇게 되면 visited에 0이 아닌수가 저장되기에 다시 방문하지 않는다
sys.setrecursionlimit(10 ** 6)
n = int(input())   # n은 노드의 개수
graph = [[] for _ in range(n+1)]   # 트리를 이중 리스트로 저장 한다 

for i in range(n-1):
    a,b = map(int, sys.stdin.readline().rstrip().split())
    # 노드는 서로 연결되어 있으므로(방향그래프가 아니므로)
    graph[a].append(b)
    graph[b].append(a)

visited = [0] * (n+1)  # 0~7
def dfs(v):
    for i in graph[v]:
        if visited[i] == 0:  # visited[i]가 0이라는건 방문 안했음
            visited[i] = v   # 부모노드를 저장
            dfs(i)
# 루트를 1이라고 정함
dfs(1)

for i in range(2, n+1):   # 2번 노드부터 순서대로 출력
    print(visited[i])
