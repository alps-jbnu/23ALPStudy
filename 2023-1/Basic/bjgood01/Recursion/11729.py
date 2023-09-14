n = int(input())  # 원판의 개수
result = 0        # 옮김 횟수
def hanoi(n, start, to, end):
    if n == 1:
        print(start, end)
    else:
        hanoi(n-1, start, end, to) # n-1개 원판을 start에서 end를 거쳐 to로 옮김
        print(start, end)          # 가장 아래 원판 보냄
        hanoi(n-1, to, start, end) # n-1개 원판을 to에서 start를 거쳐 end로 옮김

# 원판 1개면 옮긴 횟수 = 2^1 -1 => 1번
# 원판 2개면 옮긴 횟수 = 2^2 -1 => 3번
# 원판 3개면 옮긴 횟수 = 2^3 -1 => 7번
#...
result = 2 ** n -1
print(result)
hanoi(n, 1, 2, 3)
