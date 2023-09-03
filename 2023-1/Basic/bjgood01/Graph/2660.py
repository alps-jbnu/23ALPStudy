# 플로이드-와샬보다는 bfs로 풀이
# 각 점으로 가는 최소이동거리를 visited로 구하고, max값이 가장작은 것들이 회장의 후보이다
import sys
from collections import deque
n = int(input())
graph = [[] for _ in range(n+1)]  # 리스트안에 리스트가 n개 있음
while True:
    a,b = map(int, sys.stdin.readline().rstrip().split())
    if a == -1:
        break
    graph[a].append(b)
    graph[b].append(a)
    # 친구관계이므로 무방향 그래프

def bfs(start):
    visited = [-1] * (n+1) # bfs 호출때마다 visited 초기화
    visited[start] = 0     # 시작 부분은 0부터 시작
    queue = deque([start])  # 시작정점 큐에 넣어준다
    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if visited[i] == -1:
                visited[i] = visited[v] + 1
                queue.append(i)
    return max(visited)   # bfs를 다 마치고 나면 start부터 끝까지 거리가 나오므로 해당 후보의 점수 반환(낮은애들이 회장후보임)

score = 50    # 회원의 수는 50명을 넘지 않음
chairman = [] 
for i in range(1, n+1):   # 1번 노드부터 차례로
    tmp = bfs(i)
    if tmp < score:
        score = tmp
        chairman = [i]
    elif tmp == score:
        chairman.append(i)

print(score, len(chairman))   # 회장 후보의 점수와 후보의 수 출력
chairman.sort()
print(*chairman)
