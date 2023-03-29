#include <bits/stdc++.h>

using namespace std;

int tree[1000002];
int N, M;

bool solve(int x){
  long long cur = 0;
  for (int i = 0; i < N; ++i){
    if (tree[i] <= x) continue;
    cur += (tree[i] - x);
  }
  return cur >= M;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for (int i = 0; i < N; ++i) cin >> tree[i];

  int st = 0;
  int en = *max_element(tree, tree+N);

  while (st < en){
    int mid = (st+en+1)/2;
    if (solve(mid)) st = mid;
    else en = mid - 1;
  }
  
  cout << st;
}