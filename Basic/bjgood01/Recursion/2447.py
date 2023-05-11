n = int(input())
# 별의 패턴을 보면 공백으로 채워진 가운데 (N/3) x (N/3) 정사각형을 N/3의 패턴으로 둘러싼 형태이다
# 따라서 N의 패턴을 알려면 N//3의 패턴을 알아야한다
# -> 결국 3의 패턴을 가지고 9의 패턴을 알고, 9의 패턴을 가지고 27의 패턴을 아는 재귀형식이다
def star(n):   
    if n == 3:  # N이 3일때의 패턴을 return
        return ['***', '* *', '***']
    
    arr = star(n//3)  # n이 3일때, 9일때, 27일때.... 3의 제곱으로
    stars = []

    for i in arr:
        stars.append(i * 3)
    for i in arr:
        stars.append(i + ' ' * (n // 3) + i)
    for i in arr:
        stars.append(i * 3)

    return stars
print('\n'.join(star(n)))    # 리스트 요소들을 줄바꿈을 해줘서 출력해준다
