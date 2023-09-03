#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[100002];
int score[100002];
vector<int> child[100002];

void dfs(int cur) {
  if(p[cur] != -1)
    score[cur] += score[p[cur]];
  for(int nxt : child[cur])
    dfs(nxt);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> p[i];
    if(p[i] == -1) continue;
    child[p[i]].push_back(i);
  }
  while(m--) {
    int i, w;
    cin >> i >> w;
    score[i] += w;
  }
  dfs(1);
  for(int i = 1; i <= n; i++) cout << score[i] << ' ';
}
