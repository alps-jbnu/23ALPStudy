#include <bits/stdc++.h>
using namespace std;

int k, v, e;
int gr[20002];
vector<int> adj[20002];

bool solve() {
  fill(gr, gr + v + 1, -1);
  
  for(int i = 1; i <= v; i++) {
    if(gr[i] != -1) continue;

    queue<int> q;
    q.push(i);
    gr[i] = 0;

    while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(int nxt : adj[cur]) {
        if(gr[nxt] != -1){
          if(gr[nxt] == gr[cur]) return false;
          else continue;
        }
        gr[nxt] = (gr[cur] + 1)%2;
        q.push(nxt);
      }
    }
  }
  return true;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k;
  while(k--) {
    cin >> v >> e;

    for(int i = 1; i <= v; i++)
      adj[i].clear();

    int i, j;
    while(e--) {
      cin >> i >> j;
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
    if(solve()) cout << "YES\n";
    else cout << "NO\n";
  }
}
