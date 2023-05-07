import sys
sys.setrecursionlimit(100000)
from collections import deque
n = int(input())  # 정점의수
m = int(input())  # 간선의수

graph = [[i] for i in range(n+1)]
visited = [0] * (n+1)
for i in range(m):
    a,b = map(int, sys.stdin.readline().rstrip().split())
    graph[a].append(b)
    graph[b].append(a)   # a와 b가 친구 관계이면 b와 a도 친구 관계이므로 무방향 그래프


def bfs(start):
    queue = deque([start])  # 시작 정점을 큐에 넣어준다
    visited[start] = 1   # 시작 정점 방문표시 해주기
    while queue:            # 큐가 빌때까지 반복
        v = queue.popleft()
        for i in graph[v]:
            if visited[i] == 0:
                visited[i] = visited[v] + 1
                queue.append(i)

bfs(1)   #  상근이의 학번은 1
result = 0
for i in range(2, n+1):
    # 본인이거나 친구거나, 친구의 친구거나 경우의 수가 3개
    # 그다음 부터는 친구의 친구의 친구이므로 3다리를 거친다
    if visited[i] < 4 and visited[i] != 0:
        result += 1

print(result)
