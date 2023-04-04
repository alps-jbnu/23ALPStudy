import sys
n = int(input())
stack = []
for i in range(n):
    num = int(input())
    if num == 0:
        stack.pop()
    else:
        stack.append(num)
    
print(sum(stack))
