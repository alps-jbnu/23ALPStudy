#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[27];
bool vis[27];

bool dfs(int cur, int dest) {
    if(cur==dest) return true;
    for(int i{}; i<adj[cur].size(); i++) {
        int nxt{adj[cur][i]};
        if(vis[nxt]) continue;
        vis[nxt] = true;
        if(dfs(nxt, dest)) return true;
        vis[nxt] = false;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n;
    for(int i{}; i<n; i++) {
        string u, is, v;
        cin>>u>>is>>v;
        adj[u[0]-'a'].push_back(v[0]-'a');
    }
    cin>>m;
    for(int i{}; i<m; i++) {
        string u, is, v;
        cin>>u>>is>>v;
        memset(vis, false, sizeof(vis));
        dfs(u[0]-'a', v[0]-'a') ? cout<<"T\n" : cout<<"F\n";
    }

    return 0;
}