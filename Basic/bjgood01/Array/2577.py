a = int(input())
b = int(input())
c = int(input())
result = str(a * b * c)
numbers = "0123456789"
for i in range(10):
    if result.count(numbers[i]):
        print(result.count(numbers[i]))
    else:
        print(0)
