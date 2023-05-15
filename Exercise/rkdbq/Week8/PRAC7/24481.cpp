#define MAX 100001
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M, R;
priority_queue<int, vector<int>, greater<int>> adj[MAX];
int depth[MAX];
bool vis[MAX];

void dfs(int cur, int level) {
    vis[cur] = true;
    depth[cur] = level;

    while(!adj[cur].empty()) {
        int nxt{adj[cur].top()};
        adj[cur].pop();
        if(vis[nxt]) continue;
        dfs(nxt, level+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(depth, -1, sizeof(depth));
    cin>>N>>M>>R;
    for(int i{}; i<M; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push(v);
        adj[v].push(u);
    }

    dfs(R, 0);
    for(int i{1}; i<=N; i++) {
        cout<<depth[i]<<"\n";
    }
    
    return 0;
}