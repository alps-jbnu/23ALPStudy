#include <bits/stdc++.h>

using namespace std;

string town[33];
int vis[33][33];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

int town_bfs(int N, pair<int,int> cur){
    queue<pair<int,int>> q;

    q.push(cur);
    vis[cur.first][cur.second] = true;

    int nxt_x,nxt_y;
    int house = 1;

    while (!q.empty()){
        cur = q.front(); q.pop();

        for (int i=0;i<4;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < N && town[nxt_x][nxt_y] == '1' && !vis[nxt_x][nxt_y]){
                q.push(make_pair(nxt_x,nxt_y));
                vis[nxt_x][nxt_y] = true;
                house++;
            }
        }
    }

    return house;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    vector<int> house;

    cin >> N;

    for (int i=0;i<N;i++){
        cin >> town[i];
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (town[i][j] == '1' && !vis[i][j]){
                house.push_back(town_bfs(N,{i,j}));
            }
        }
    }

    sort(house.begin(),house.end());

    int towns = house.size();

    cout << towns << '\n';
    for (int i=0;i<towns;i++){
        cout << house[i] << '\n';
    }

    return 0;
}
