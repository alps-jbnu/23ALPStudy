#include <bits/stdc++.h>
using namespace std;
#define ll long long // -2^63 ~ 2^63-1
#define pii pair<ll, ll>
#define X first
#define Y second
#define Z third

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll result; // 가장 오래 기다리는 소의 시간
int n;
int a[100005], t[100005]; // 소들이 도착한 시간과 풀 먹는데 걸린 시간

vector<pair<ll, pii>> cow;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
#ifndef ONLINE_JUDGE
  freopen("E:/vsCode_C++/input.txt", "r", stdin);
  freopen("E:/vsCode_C++/output.txt", "w", stdout);
#endif

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> t[i];
    cow.push_back({a[i], {t[i], i}});
  }

  sort(cow.begin(), cow.end());

  ll start_endTime = cow[0].X + cow[0].Y.X; // 첫번째 시작 시간에서 끝나는 시간
  int count = 1; // 주어진 소들의 수가 맞는지 판별하기 위한 변수

  while (count < n || !pq.empty()) {
    // 기다리는 소들의 조건(st_en 보다 작은 '도착시간'들을 pq에 집어 넣음)
    while (count < n && cow[count].X <= start_endTime) {
      pq.push({cow[count].Y.Y, count});
      count++;
    }

    if (!pq.empty()) {
      ll seniority, index;
      tie(seniority, index) = pq.top();
      pq.pop();

      result = max(result, start_endTime - cow[index].X);
      start_endTime += cow[index].Y.X;
    }
    // 기다리는 소들이 없고 겹치는게 없다면 바로 그 다음의 cow의 a[i], t[i]를 더함
    else {
      start_endTime = cow[count].X + cow[count].Y.X;
      count++;
    }
  }

  cout << result;
  return 0;
}
