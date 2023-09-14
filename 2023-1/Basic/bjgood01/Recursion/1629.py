# 반복문으로 풀면 시간초과, 분할정복으로 풀어야함
# 짝수일경우 2^10 = 2^5 * 2^5
# 홀수일경우 2^11 = 2^5 * 2^5 * 2
# 즉 절반으로 나눠서 계산
a,b,c = map(int, input().split())
def divide(a,b):
    if b == 1:   # 차수가 1
        return a % c
    
    temp = divide(a, b // 2)

    # 짝수이면 temp * temp
    if b % 2 == 0:
        return temp * temp % c
    
    else:  # 홀수이면 a * temp * temp
        return a * temp * temp % c
    
print(divide(a,b))
