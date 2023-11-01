#include <bits/stdc++.h>
using namespace std;

int n, m, x, a, b;
vector<int> adjBack[100001];
vector<int> adjFront[100001];
bool vis[100001];

int findMin(int x) {
  int cnt = 0;
  queue<int> q;
  vis[x] = 1;
  q.push(x);
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < adjFront[cur].size(); i++) {
      int nxt = adjFront[cur][i];
      if (!vis[nxt]) {
        q.push(nxt);
        vis[nxt] = 1;
        cnt++;
      }
    }
  }
  return 1 + cnt;
}

int findMax(int x) {
 int cnt = 0;
  queue<int> q;
  vis[x] = 1;
  q.push(x);
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < adjBack[cur].size(); i++) {
      int nxt = adjBack[cur][i];
      if (!vis[nxt]) {
        q.push(nxt);
        vis[nxt] = 1;
        cnt++;
      }
    }
  }
  return n - cnt;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adjBack[a].push_back(b);
    adjFront[b].push_back(a);
  }
  cout << findMin(x) << " " << findMax(x);
}
