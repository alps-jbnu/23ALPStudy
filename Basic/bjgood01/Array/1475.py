s = input()
numbers = [0 for i in range(10)]  # 0 ~ 9까지 0으로 채워둔다 

for item in s:
    if item == '9':      
        numbers[6] += 1
    else:
        numbers[int(item)] += 1
if numbers[6] % 2:  # 홀수개면 6-9 대체해도 하나가 더 남아서 세트하나 더 추가
    numbers[6] = numbers[6] // 2 + 1 # 세트 하나더 추가 해야한다
else:
    numbers[6] = numbers[6] // 2

print(max(numbers))
