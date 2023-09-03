#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[2001];
bool vis[2001];

bool dfs(int cur, int level) {
    if(level==5) return true;
    for(int nxt : adj[cur]) {
        if(vis[nxt]) continue;
        vis[nxt] = true;
        if(dfs(nxt, level+1)) return true;
        vis[nxt] = false;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    for(int i{}; i<M; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans{};
    for(int i{}; i<N; i++) {
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        if(dfs(i, 1)) {
            ans = true;
            break;
        }
    }
    cout<<ans<<"\n";

    return 0;
}