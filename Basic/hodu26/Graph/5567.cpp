#include <bits/stdc++.h>

using namespace std;

vector<int> friends[503]; // adjacency list 인접 리스트
bool vis[503];

queue<int> q;

int invite_bfs(int invite){
    int floor = 0;

    int size = q.size();

    while (!q.empty()){
        int cur = q.front(); q.pop();
        size--;

        for (int nxt : friends[cur]){
            if (!vis[nxt]){
                q.push(nxt);
                vis[nxt] = true;
                invite++;
            }
        }

        if (size == 0){
            size = q.size();
            floor++;
        }

        if (floor == 2) return invite;
    }
    return invite;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,a,b;

    cin >> n;
    cin >> m;

    while (m--){
        cin >> a >> b;

        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    q.push(1);
    vis[1] = true;
    cout << invite_bfs(0);

    return 0;
}
