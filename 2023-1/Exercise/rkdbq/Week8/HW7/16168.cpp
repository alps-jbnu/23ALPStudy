#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int V, E;
vector<pair<int, int>> adj[3001];
bool edges[3001];

string dfs(int cur, int level) {
    if(level==E) return "YES";
    for(int i{}; i<adj[cur].size(); i++) {
        if(edges[adj[cur][i].second]) continue;
        int nxt{adj[cur][i].first};
        edges[adj[cur][i].second] = true;
        return dfs(nxt, level+1);
        edges[adj[cur][i].second] = false;
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>V>>E;
    for(int i{}; i<E; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    string ans{"NO"};
    for(int i{1}; i<=V; i++) {
        if(dfs(i, 0)=="YES") {
            ans = "YES";
            break;
        }
        fill(edges, edges+3001, false);
    }
    cout<<ans;

    return 0;
}