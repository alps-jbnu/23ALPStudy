N, K = map(int, input().split())
count = 0  # 필요한 방의 최소 개수
boy = [0 for i in range(6)]
girl = [0 for i in range(6)]
for i in range(N):
    S, Y = map(int, input().split())
    if S == 0: # 여자
        if Y == 1:
            girl[0] += 1
        elif Y == 2:
            girl[1] += 1
        elif Y == 3:
            girl[2] += 1
        elif Y == 4:
            girl[3] += 1
        elif Y == 5:
            girl[4] += 1
        else:
            girl[5] += 1
    else:  # 남자
        if Y == 1:
            boy[0] += 1
        elif Y ==2:
            boy[1] += 1
        elif Y == 3:
            boy[2] += 1
        elif Y == 4:
            boy[3] += 1
        elif Y == 5:
            boy[4] += 1
        else:
            boy[5] += 1

for i in range(6):
    if girl[i] < K and girl[i] > 0:
        count += 1
    elif girl[i] == K and girl[i] > 0:
        count += 1
    elif girl[i] > K:
        count += (girl[i] // K) + (girl[i] % K)
    if boy[i] < K and boy[i] > 0:
        count += 1
    elif boy[i] == K and boy[i] > 0:
        count += 1
    elif boy[i] > K:
        count += (boy[i] // K) + (boy[i] % K)

print(count)
