#include <bits/stdc++.h>

using namespace std;

vector<int> graph[20003]; // adjacency list 인접 리스트
int vis[20003];

stack<int> s;

bool check_dfs(int floor, int nC){
    int cur = s.top(); s.pop();

    for (int nxt : graph[cur]){
        
        if (vis[nxt] <= 0){

            if (floor%2 == 0){
                vis[nxt] = 1 + nC;
            }
            else {
                vis[nxt] = 2 + nC;
            }

            s.push(nxt);
            if (!check_dfs(floor+1,nC)) return false;
        }
        else if (vis[nxt] == vis[cur]){
            cout << "NO\n";
            return false;
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int K,V,E,u,v, notConnect=0;
    bool flag;

    cin >> K;

    while (K--){
        cin >> V >> E;

        while (E--){
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i=1;i<=V;i++){  // 비연결 그래프의 가능성도 있어서 이 코드가 필요함 (notConnected graph)
            if (vis[i] == 0){
                s.push(i);
                vis[i] = 2 + notConnect;
                flag = check_dfs(0,notConnect);
                if (!flag) break;
            }
            notConnect += 2;
        }
        if (flag) cout << "YES\n";

        for (int i=1;i<=V;i++){
            while(!graph[i].empty()) graph[i].pop_back();
            vis[i] = 0;
        }
        notConnect = 0;
    }

    return 0;
}
