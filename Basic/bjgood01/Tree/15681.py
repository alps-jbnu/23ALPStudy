import sys
sys.setrecursionlimit(10 ** 6)
# 트리에서 마지막 입력받는 정점을 root로 하는 서브트리의 정점의수를 출력
# dfs로 탐색하면서 각 정점에 대한 서브트리의 수를 count 배열에 담아준다
def dfs(x):
    count[x] = 1 # 방문표시
    for i in graph[x]:
        if not count[i]:   # 방문한적 없다면 dfs 수행
            dfs(i)
            count[x] += count[i]

n, r, q = map(int, input().split())
graph = [[] for _ in range(n+1)]
count = [0] * (n+1)  # count배열로 방문표시까지 해준다
for _ in range(n-1):  # 간선의수는 정점-1
    a,b = map(int, sys.stdin.readline().rstrip().split())
    graph[a].append(b)
    graph[b].append(a)

dfs(r)  # r을 root로 한다
# 결국 count 배열은
# count = [0, 1, 1, 3, 4, 9, 4, 1, 1, 1]이 된다
for _ in range(q):
    i = int(sys.stdin.readline().rstrip())
    print(count[i])
