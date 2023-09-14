#include <bits/stdc++.h>
using namespace std;

int n;
int p[100001];
vector<int> tree[100001];

void dfs(int idx){
  for (int nxt : tree[idx]){
    if(p[idx] == nxt) continue;
    p[nxt] = idx;
    dfs(nxt);
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++){
    int u,v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs(1);
  for(int i = 2; i <= n; i++) cout << p[i] <<"\n";
}
