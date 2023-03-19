import sys
n = int(sys.stdin.readline())
numbers = list(map(int, input().split()))
x = int(input())
# 내장함수 sort 이용
numbers.sort()
count = 0
i = 0
j = n-1
while True:
    if numbers[i] + numbers[j] == x:
        count += 1

    if numbers[i] + numbers[j] > x:
        j -= 1
    
    else:
        i += 1
    
    # i가 j보다 크거나 같아지면 종료
    if i >= j:
        break
print(count)
