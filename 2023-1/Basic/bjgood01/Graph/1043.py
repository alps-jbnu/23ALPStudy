# 진실을 알고 있는 사람의 집합을 knowList
# 파티에 참석한 사람의 집합을 party
# party를 원소로 갖는 리스트 parties
# 만약 party, knowList의 교집합이 하나라도 있으면 knowList = knowList.union(party) 가 된다
#-> 파티에 진실을 아는 사람이 한명이라도 있으면, 그 사람으로 인해 파티에 참석한 모든 사람이 진실을 알게됨
import sys
n,m = map(int, input().split())  # n은 사람수, m은 파티수
# 진실을 알고있는 사람수 먼저 입력하고, 사람 번호를 입력하므로 [1:] 으로 스플라이싱 해준다
knowList = set(sys.stdin.readline().rstrip().split()[1:])
parties = []

for _ in range(m):
    parties.append(set(sys.stdin.readline().rstrip().split()[1:]))
    # 파티에 참석하는 사람들을 입력하는데, 오는 사람의수 먼저 입력하고, 번호를 입력하므로 [1:] 해준다

for _ in range(m):
    for party in parties:   # 집합이 차례로 party에 대입됨(파티에 참석한 사람들)
        if party & knowList:  # 둘의 교집합이 하나라도 있으면
            knowList = knowList.union(party)

cnt = 0  # 갈수 있는 파티 개수
for party in parties:
    if party & knowList:  # 둘의 교집합이 하나라도 있으면 파티에 못가므로 continue
        continue
    cnt += 1  # 교집합이 없을때 1증가 해준다

print(cnt)
