#include <bits/stdc++.h>
using namespace std;

int n, ans;
pair<int, int> user[100001];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
set<int> seat;
int cnt[100001];

int func(){
  int res = 0;
  for (int i = 0; i < n; i++) {
    while (!pq.empty()) { // 시작 시간보다 빨리 끝나는 사람들
      if (pq.top().first <= user[i].first) {
        seat.insert(pq.top().second);
        pq.pop();
      }
      else break;
    }
    if (seat.empty()) { // 남는 자리 없는 경우
      pq.push({user[i].second, res});
      cnt[res++]++;
    }
    else { // 새로운 의자
      pq.push({user[i].second, *seat.begin()});
      cnt[*seat.begin()]++;
      seat.erase(seat.begin());
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) cin >> user[i].first >> user[i].second;
  
  sort(user, user + n);
  ans = func();
  cout << ans << "\n";
  for (int i = 0; i < ans; i++) cout << cnt[i] << " ";
}
