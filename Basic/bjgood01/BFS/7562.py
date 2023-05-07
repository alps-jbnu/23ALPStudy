import sys
from collections import deque
T = int(input())

def bfs():
    # 나이트가 이동할수 있는 거리  => 총 8방향
    dx = [-2, -1, 1, 2, 2, 1, -1, -2]
    dy = [-1, -2, -2, -1, 1, 2, 2, 1]

    # 큐 구현을 위한 덱 사용
    queue = deque()
    queue.append((sx,sy))
    while queue:
        x,y = queue.popleft()  # 큐 맨앞 좌표 빼낸다
        if x == ex and y == ey:   # 큐에서 꺼낸 좌표가 도착 좌표이면
            return matrix[x][y] - 1   # 1부터 시작했으므로 -1을 해주어야 한다(같은 자리로 가면 0이므로)
        for i in range(8): # 이동 확인
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < l and 0 <= ny < l and matrix[nx][ny] == 0:
                matrix[nx][ny] = matrix[x][y] + 1  # 이동할때마다 이전값에 +1을 저장해준다
                queue.append((nx,ny))

for _ in range(T):
    l = int(sys.stdin.readline().rstrip())  # 체스판 한변의 길이
    sx,sy = map(int, sys.stdin.readline().rstrip().split())   # 출발
    ex,ey = map(int, sys.stdin.readline().rstrip().split())   # 도착
    matrix = [[0] * l for _ in range(l)]    # 전부 0으로 초기화 해준다
    matrix[sx][sy] = 1   # 시작 좌표값을 1로 둔다 
    print(bfs())

