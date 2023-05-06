# 플로이드 워셜 알고리즘 
# 모든 노드에서 다른 모든 노드까지의 최단경로를 모두 계산한다
# 플로이드 워셜 알고리즘은 다익스트라알고리즘 과 마찬가지로 단계별로 거쳐가는 노드를 기준으로 알고리즘을 수행
# 플로이드 워셜은 2차원 테이블에 최단거리 정보를 저장한다
# 플로이드 워셜 알고리즘 점화식 D(ab) = min(D(ab), D(ak) + D(kb))
#-> a에서 b로 가는 최단거리보다 a에서 k를 거쳐 b로 가는 거리가 더 짧은지 검사한다
# 플로이드 워셜 알고리즘을 구현할때 3중 for문 이용 k는 거쳐가는 노드, a는 출발노드, b는 도착노드
import sys
n = int(input())
graph = []
visited = [[0] for _ in range(n)]
for i in range(n):
    graph.append(list(map(int, sys.stdin.readline().rstrip().split())))


# 점화식에 따라 플로이드 워셜 알고리즘 수행
#-> a에서 b로 가는 최단거리보다 a에서 k를 거쳐 b로 가는 거리가 더 짧은지 검사한다
# for문 3개 이용
for i in range(n):                 # i는 거쳐가는 노드
    for j in range(n):             # j는 출발노드
        for k in range(n):         # k는 도착노드
            if graph[j][i] and graph[i][k]:   # 출발->거쳐가는노드->도착 노드까지 유효하면
                graph[j][k] = 1

for a in graph:
    print(*a)
