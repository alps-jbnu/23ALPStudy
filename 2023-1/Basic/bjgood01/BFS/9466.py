# 사이클을 형성하는것만 팀이 될수 있다 -> 사이클을 형성하는 번호를 제외한 나머지가 어느 프로젝트에도 속하지 않는 학생의 수
# 사이클을 판단하는 방법으로 dfs를 활용
# 1번 정점부터 시작하여 연결된 간선을 따라가다 이미 방문한 노드에 도달하면, 지나온 노드가 사이클을 이룰경우
# 사이클의 크기만큼 결과값에 제외하는 방식
import sys
sys.setrecursionlimit(10 ** 7)

def dfs(x):
    global ans   # 전역변수로 활용
    visited[x] = True  # 방문 표시
    cycle.append(x)
    num = graph[x]     # x정점이 가리키는 것을 num에 넣어준다

    if visited[num]:  # 방문한적있으면
        if num in cycle:  # 사이클 리스트에 num이 들어 있으면
            ans += cycle[cycle.index(num):]   # num이 있는 인덱스 위치부터 끝까지 splicing 해서 ans에 합쳐준다
            #-> 싸이클형성 제외 나머지 학생들
        return
    else:
        dfs(num)   # num위치를 방문한적없으면 dfs 수행 해준다

t = int(input())  # 테스트 케이스
for _ in range(t):
    n = int(sys.stdin.readline().rstrip())
    graph = [0] + list(map(int, sys.stdin.readline().rstrip().split()))  # [0, ...]
    visited = [False] * (n+1)  # 방문표시 배열
    ans = []   # 사이클 형성 학생 리스트(나중에 전체에서 이 리스트를 빼줘야 어느 프로젝트에도 속하지 않는 학생들이 나온다)

    for i in range(1, n+1):  # 1번 정점부터 시작하여 연결된 간선을 따라간다
        if not visited[i]:
            cycle = []       # cycle 리스트는 다시 reset
            dfs(i)

    print(n - len(ans))  # 전체 학생수 - 사이클형성한 학생들
