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
            cout << nxt << ' ';
            find_dfs();
        }
    }
    return ;
}

queue<int> q;

void find_bfs(){

    while (!q.empty()){
        int cur = q.front(); q.pop();

        for (int nxt : graph[cur]){
            if (!vis[nxt]){
                q.push(nxt);
                vis[nxt] = true;
                cout << nxt << ' ';
            }
        }
    }
    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M,V,u,v;

    cin >> N >> M >> V;

    while (M--){
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i=1;i<=N;i++){
        sort(graph[i].begin(), graph[i].end());
    }

    s.push(V);
    vis[V] = true;
    cout << V << ' ';
    find_dfs();

    cout << '\n';

    fill(vis+1, vis+N+1, false); // vis 초기화

    q.push(V);
    vis[V] = true;
    cout << V << ' ';
    find_bfs();

    return 0;
}
