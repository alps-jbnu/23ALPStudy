#include <bits/stdc++.h>

using namespace std;

vector<int> network[103]; // adjacency list 인접 리스트
bool vis[103];

stack<int> s;

int infection_dfs(int infection){
    int cur = s.top(); s.pop();

    for (int nxt : network[cur]){
        if (!vis[nxt]){
            s.push(nxt);
            vis[nxt] = true;
            infection = infection_dfs(infection+1);
        }
    }
    return infection;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M,u,v;

    cin >> N;
    cin >> M;

    while (M--){
        cin >> u >> v;

        network[u].push_back(v);
        network[v].push_back(u);
    }

    s.push(1);
    vis[1] = true;
    cout << infection_dfs(0);

    return 0;
}
