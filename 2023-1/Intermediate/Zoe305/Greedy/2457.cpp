#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> flower;
  for (int i = 0; i < n; i++) {
    int sm, sd, em, ed;
    cin >> sm >> sd >> em >> ed;
    flower.push_back({sm * 100 + sd, em * 100 + ed}); // 날짜는 대충 파싱해도 됨
  }

  int t = 301;
  int ans = 0;
  while (t < 1201) {
    int nxt_t = t;
    for(int i = 0; i < n; i++){
      if(flower[i].X <= t && flower[i].Y > nxt_t)
        nxt_t = flower[i].Y;
    }
    if(nxt_t == t){
      cout << 0;
      return 0;
    }
    ans++;
    t = nxt_t;
  }
  cout << ans;
}
/*
입력받은 것을 어떻게 저장해야 하나 고민을 많이 하다가 답지를 보고 파싱하는 법도 있구나를 깨달음
날짜 하나씩 체크하면서 해당 시점에 피어있는 꽃들 중 가장 마지막으로 지는 꽃을 고르자는 아이디어는 생각해
*/