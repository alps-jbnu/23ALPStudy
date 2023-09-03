#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
bool vis[100001];

void dfs(int cur){
    if(vis[cur]) return;
    vis[cur] = true;
    for(auto nxt : adj[cur])
        dfs(nxt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int groupcnt = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        dfs(i);
        groupcnt++;
    }
    cout << (groupcnt-1) + (m+groupcnt-1)-(n-1);
}

/*
우선 connected component의 개수(=groupcnt)를 셉니다. groupcnt-1개의 간선을 추가해 주어진 그래프를 연결 그래프로 만듭니다.
현재 그래프에는 m+groupcnt-1개의 간선이 있고 트리는 n-1개의 간선이 있기 때문에 (m+groupcnt-1)-(n-1)개의 간선을
제거해야 합니다. 최종적으로 답은 (groupcnt-1) + (m+groupcnt-1)-(n-1) 입니다.


 #include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;

int n, m;
int cnt, p[MX + 2];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void try_merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) { cnt++; return; }
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  fill(p, p+n+1, -1);
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    try_merge(u, v);
  }

  cout << n - m - 1 + 2*cnt;
}

유니온 파인드를 활용한 별해입니다.

간선을 입력 받으면서 merge를 시도합니다.
두 정점의 부모가 동일하지 않다면 merge를 수행합니다.
두 정점의 부모가 동일한 경우
해당 간선은 불필요한 간선이므로
자르는 연산 횟수인 cnt를 증가시킵니다.

이 연산을 완료한 뒤에 남은 간선 수는 총 (m - cnt)개가 됩니다.
여기서 간선을 연결해 (n - 1)개의 간선을 확보해야 트리가 구성됩니다.
따라서 연결해야 하는 간선 수는 (n - 1) - (m - cnt)개가 됩니다.

그러므로 간선을 잇고 자르는 총 연산 수는
(n - 1) - (m - cnt) + cnt = n - m - 1 + 2*cnt이며,
이를 답으로 출력합니다.
*/