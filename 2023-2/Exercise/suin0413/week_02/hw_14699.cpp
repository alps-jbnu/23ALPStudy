#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int height[5001];
vector<int> adj[5001];
int d[5001];

int func(int cur){
  if (d[cur] != 0) return d[cur];
  for (int i = 0; i < adj[cur].size(); i++)
    d[cur] = max(d[cur], func(adj[cur][i]));
  return ++d[cur];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 1; i <= n; i++) cin >> height[i];
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (height[a] > height[b]) adj[b].push_back(a);
    else adj[a].push_back(b);
  }
  for(int i = 1; i <= n; i++) {
    cout << func(i) << "\n";
  }
}
