#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1003]; // adjacency list 인접 리스트
bool vis[1003];

stack<int> s;

void find_dfs(){
    int cur = s.top(); s.pop();

    for (int nxt : graph[cur]){
        if (!vis[nxt]){
            s.push(nxt);
            vis[nxt] = true;
            find_dfs();
        }
    }
    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M,u,v, comp=0;

    cin >> N >> M;

    while (M--){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1;i<=N;i++){
        if (!vis[i]){
            s.push(i);
            vis[i] = true;
            find_dfs();
            comp++;
        }
    }

    cout << comp;

    return 0;
}
