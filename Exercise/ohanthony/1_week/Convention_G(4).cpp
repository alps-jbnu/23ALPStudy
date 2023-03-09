#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define X first
#define Y second

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, c;
/*
- n: 소의 수
- m: 버스 개수
- c: 버스가 태울 수 있는 소의 수
*/

vector<int> arriveTime;

// mid 시간 안에 모든 소들이 탑승이 가능한지
bool isRideBus(int time) {
  int bus = 1; // 필요한 버스의 수
  int st = 0;  // 처음 버스를 타는 소의 시간

  for (int i = 1; i < n; i++) {
    if (i - st >= c || arriveTime[i] - arriveTime[st] > time) {
      bus++;
      st = i;
    }
  }

  return bus <= m;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> c;
  for (int i = 0; i < n; i++) {
    int time;
    cin >> time;
    arriveTime.push_back(time);
  }

  // 1. 도착한 시간을 오름차순으로 정렬
  sort(arriveTime.begin(), arriveTime.end());

  int st = 0;
  int en = arriveTime[n - 1]; // 입력으로 주어진 시간 중 최대 시간

  while (st <= en) { // 2. 이진 탐색
    int mid = (st + en) / 2;

    if (isRideBus(mid))
      en = mid - 1;
    else
      st = mid + 1;
  }

  cout << st << '\n';

  return 0;
}

/*
(Parametric Search)
- 조건을 만족하는 최소/최대값을 구하는 문제
- 최적화 문제를 '결정 문제'로 변환해 이분탐색을 수행

- 시간복잡도 = 이진탐색 O(log N) x O(N) = O(NlgN)

1. STL sort => 퀵 정렬, O(NlgN)
2. mid 시간 안에 소들이 버스에 탈 수 있는지 '결정 문제'로 바꾸는 것
  - 버스에 탈 수 있는 소의 수가 초과시 버스 하나를 추가하고 처음 버스를 타는
소의 시간을 바꾼다.
*/