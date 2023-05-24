import sys
# 입력된 인덱스를 dfs 함수에 트리배열과 함께 전달

def dfs(k, arr):
    arr[k] = -2   # 배열값을 삭제한다는 의미로 -2로 바꿔준다(-1은 루트 노드와 겹치므로 피한다)
    for i in range(len(arr)):
        # 배열 전체를 탐색하며, 방금삭제한 노드를 부모노드로 가지는 노드를 찾아 dfs 재귀호출
        if k == arr[i]:  
            dfs(i, arr)

n = int(input())  # n은 노드의 개수
# 루트노드는 부모가 없으므로 -1이 입력되고, 나머지는 각 노드의 부모노드를 입력
arr = list(map(int, input().split())) 
k = int(input())  # k는 지울 노드의 번호
leaf = 0  # 리프노드의 개수

dfs(k, arr)  # 매개변수로 지울 노드의 번호와 , 리스트를 넘겨준다
# 재귀호출이 다 끝나있으면 삭제할 노드들은 전부 -2로 갱신되어 있다
# -2가 아니면서, 다른 노드의 부모노드도 아닌 리프노드를 찾을때마다 leaf 1씩 증가 시켜준다
for i in range(len(arr)):
    if arr[i] != -2:
        if i not in arr:
            leaf += 1

print(leaf)
