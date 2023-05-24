# 2번의 dfs를 이용한다, 첫번째 dfs는 단순히 모든 노드들을 이동하면서 거리를 구한다
# dfs2는 오로지 한방향으로만 이동하는 지점 즉, 항상 오른쪽으로 가는 지점에 대해서는 오로지 한번씩만 방문한다
# dfs1으로 구한값을 count라 하고, dfs2로 구한 값을 count2라 하면  2 * count - count2를 하면 나온다
import sys
sys.setrecursionlimit(10 ** 6)
n = int(input())  # n은 노드의 개수
tree = {}         # 트리를 사전형으로 표현
count = 0
for i in range(n):
    data, left_node, right_node = map(int, sys.stdin.readline().rstrip().split())
    tree[data] = [left_node, right_node]  # {A: [B,C]} 이런 식으로 저장

# 일반적인 dfs를 해서 중위순회 하는 함수
def dfs(node):
    global count
    visited[node] = True  # 방문처리
    if not visited[tree[node][0]] and tree[node][0] != -1:  # 왼쪽 자식을 방문처리 안되어 있고, -1이 아니라면(-1은 자식노드가 없다는 소리)
        dfs(tree[node][0])   # 왼쪽서브트리
        count += 1
    if not visited[tree[node][1]] and tree[node][1] != -1: # 오른쪽 자식을 방문처리 안되어 있고, -1이 아니라면
        dfs(tree[node][1])  # 오른쪽 서브트리
        count += 1

# 오로지 오른쪽으로만 이동하는 dfs
def dfs2(node):  
    global count2
    visited[node] = True
    if not visited[tree[node][1]] and tree[node][1] != -1:  # 오른쪽 자식을 방문처리 안되어 있고, -1이 아니라면
        dfs2(tree[node][1])
        count2 += 1
visited = [False] * (n+1)
count = 0
dfs(1)  # 루트노드는 1
count2 = 0
visited = [False] * (n+1)
dfs2(1)

# count: dfs로 구한 값
# count2: dfs2로 구한값
print(2 * count - count2)
