# 트리를 사전으로 간단하게 표현
# ex) {A : [B,C]},   key값이 A이면 value가 [B,C]이다
# '.'이 아닐때만 전위,중위,후위 순회를 실시
import sys
n = int(input())  # 이진트리 노드의 개수
tree = {}         # 트리를 사전형으로 표현
for i in range(n):
    data, left_node, right_node = sys.stdin.readline().rstrip().split()
    tree[data] = [left_node, right_node]   # 각 노드마다 자식들 설정을 해준다  {A: [B,C]}
# 전위순회
def preorder(data):
    if data != '.':
        print(data, end='')      # V
        preorder(tree[data][0])  # L
        preorder(tree[data][1])  # R

# 중위순회
def inorder(data):
    if data != '.':
        inorder(tree[data][0])  # L
        print(data, end='')     # V
        inorder(tree[data][1])  # R

# 후위순회
def postorder(data):
    if data != '.':
        postorder(tree[data][0]) # L
        postorder(tree[data][1]) # R
        print(data, end='')      # V

# 항상 루트는 A, 자식이 없는 경우 .으로 표현
preorder('A')
print()
inorder('A')
print()
postorder('A')
