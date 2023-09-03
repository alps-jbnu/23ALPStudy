import sys
n = int(input())

matrix = [list(map(int, input())) for _ in range(n)]
def recur(x,y,n):
    visited = matrix[x][y]
    for i in range(x, x+n):
        for j in range(y, y+n):
            if visited != matrix[i][j]:  # 다르면 4등분을 해준다
                visited = -1
                break

    if visited == -1:
        print('(', end='')
        recur(x,y,n//2)
        recur(x,y + n//2, n//2)
        recur(x + n//2, y, n//2)
        recur(x + n//2, y + n//2, n//2)
        print(')', end='')
                            
    elif visited == 1:
        print(1, end='')
    else:
        print(0, end='')
recur(0,0,n)
