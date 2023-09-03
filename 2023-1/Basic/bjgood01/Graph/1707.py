# 이분그래프는 인접한 정점끼리 서로 다른 색으로 칠해서 모든 정점을 2가지 색으로만 칠할수 있는 그래프라 보면된다
# dfs 탐색을 진행하며, 현재 노드와 이웃한 노드의 색을 확인하고, 동일한 색으로 칠해져 있다면
# 이분그래프가 아닌것으로 판단
import sys
sys.setrecursionlimit(10 ** 7)
t = int(input())

def dfs(node):  # 이웃한 노드들 탐색하기위해 dfs 탐색 활용
    global result
    for neighbor in graph[node]:
        if visited[neighbor] == -1:  # 이웃 노드가 색칠이 되어 있지 않으면
            # 현재 노드가 1로 색칠되어 있으면 이웃노드 2로 색칠
            if visited[node] == 1:
                visited[neighbor] = 2
            # 현재 노드가 2로 색칠되어 있으면 이웃노드 1로 색칠
            if visited[node] == 2:
                visited[neighbor] = 1

            dfs(neighbor)   # 이웃노드부터 dfs 탐색 수행

        # 이웃 노드에 색칠이 되어 있으면
        else:
            if visited[node] == visited[neighbor]:  # 현재노드와 동일한 색깔이라면
                result = False   # 이분 그래프가 아니다
                return



for _ in range(t):
    # v: 정점의 개수, e: 간선의 개수4
    v,e = map(int, sys.stdin.readline().rstrip().split())
    visited = [-1] * (v+1)            # 색칠 여부
    graph = [[] for _ in range(v+1)]  # 리스트안에 v+1개의 리스트가 있는 이중리스트
    # 양방향 간선 정보 저장
    for _ in range(e):
        start, end = map(int, sys.stdin.readline().rstrip().split())
        graph[start].append(end)
        graph[end].append(start)

    # 이분 그래프 여부
    result = True
    # 모든 노드 탐색
    for i in range(1, v+1):
        if visited[i] == -1:  # 현재노드가 색칠되어 있지 않으면
            visited[i] = 1    # 현재노드를 색칠한다
            dfs(i)            # 이웃한 노드에 대해 색칠
            # 현재 노드로부터 이분그래프가 아닌것을 확인했다면
            if result == False:
                break
    # 이분 그래프가 아니라면
    if result == False:
        print('NO')
    else:
        print('YES')
