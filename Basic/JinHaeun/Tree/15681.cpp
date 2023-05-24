#include <iostream>
#include <vector>
using namespace std;

int N, R, Q, u, v, q, subTreeSize[100001];
vector<int> adj[100001];
vector<bool> vis(100001);

int dfs(int cur) {
    if (subTreeSize[cur] != 0) 
        return subTreeSize[cur];
    vis[cur] = true;
    int ret = 1;
    for (int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if (vis[nxt]) continue;
        ret += dfs(nxt);
    }
    subTreeSize[cur] = ret;
    return subTreeSize[cur];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    subTreeSize[R] = dfs(R);

    while (Q--) {
        cin >> q;
        cout << subTreeSize[q] << '\n';
    }
}
