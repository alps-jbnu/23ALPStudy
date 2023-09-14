import sys
n = int(input())

matrix = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(n)]
answer = [0,0,0]
def recur(x,y,n):
    global answer
    visited = matrix[x][y]

    for i in range(x, x+n):
        for j in range(y, y+n):
            # 시작점의 종이의수와 현재 종이의수가 다르다면
            if matrix[i][j] != visited:
                # 3*3 범위를 재귀적으로 탐색
                for a in range(3):
                    for b in range(3):
                        recur(x + n//3 * a, y + n//3 * b, n//3)
                return


    # 카운트
    if visited == -1:
        answer[0] += 1
    elif visited == 0:
        answer[1] += 1
    else:
        answer[2] += 1


recur(0,0,n)
for i in answer:
    print(i)    
