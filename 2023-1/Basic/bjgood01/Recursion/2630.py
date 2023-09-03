import sys
n = int(input())
matrix = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(n)]
answer = [0, 0]   # 흰, 파


def recur(x,y,n):
    global answer
    visited = matrix[x][y]

    for i in range(x, x+n):
        for j in range(y, y+n):
            # 색상이 모두 같지 않으면 4등분 해준다
            if matrix[i][j] != visited:
                recur(x, y, n//2)
                recur(x, y + n//2, n//2)
                recur(x + n//2, y, n//2)
                recur(x + n//2, y + n//2, n//2)
                return # 4등분이 끝나면 종료
                
            
    # 카운트
    if visited == 0:  # 흰색
        answer[0] += 1
    else:             # 파란색
        answer[1] += 1

recur(0,0,n)
for i in answer:
    print(i)
