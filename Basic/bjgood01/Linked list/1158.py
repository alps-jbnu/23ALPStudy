# n: 사람수, k: k번째 사람 제거
# 스택 2개를 이용해서 왼쪽스택에서 pop()한것을 오른쪽 스택으로 append 해준다
# 오른쪽 스택에 모여 있는것을 join 메서드로 이용해 출력
n, k = map(int, input().split())
# 왼쪽 스택: 1~n까지 들어있는 리스트
stack_l = [i for i in range(1, n+1)]
# 오른쪽 스택: 왼쪽스택에서 제거된 요소를 append 해준 리스트
stack_r = []
# 제거를 편하게 하기위해 제거될 인덱스 번호 num
num = 0
# 총 n번 반복을 해야 n개의 원소가 제거된다
for i in range(n):
    num += (k-1)   # 제거될 인덱스 번호는 k-1번째 원소이다
    if num >= len(stack_l):   # 제거될 인덱스 번호가 왼쪽 스택의 크기보다 크면 num 다시 설정
        num = num % len(stack_l)
    
    # 왼쪽스택 pop하고, 오른쪽 스택에 append
    stack_r.append(str(stack_l.pop(num)))   # str 형변환을 하는 이유는 join메서드를 사용하기 위해서

print('<'+', '.join(stack_r)+'>')
