#include <bits/stdc++.h>

using namespace std;

vector<int> G[103]; // adjacency list 인접 리스트

int vis[103][103];

stack<int> s;

void find_dfs(int i){
    int cur = s.top(); s.pop();

    for (int nxt : G[cur]){
        if (vis[cur][nxt] != i){
            s.push(nxt);
            vis[cur][nxt] = i;
            vis[i][nxt] = i;
            find_dfs(i);
        }
    }
    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,inpt;

    cin >> N;

    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            cin >> inpt;
            if (inpt == 1){
                G[i].push_back(j);
            }
        }
    }

    for (int i=1;i<=N;i++){
        s.push(i);
        find_dfs(i);

        for (int j=1;j<=N;j++){
            if (vis[i][j] == 0){
                cout << 0 << ' ';
            }
            else {
                cout << 1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
