#include <bits/stdc++.h>

using namespace std;

int country[103][103];
bool vis[103][103];
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};

vector<pair<int,int>> edge;   // <x,y>
queue<int> div_idx;   // {first island edge start idx, second island edge start idx ... }

void find_edge_bfs(int N, pair<int,int> cur){
    queue<pair<int,int>> q;

    int nxt_x,nxt_y;
    bool pushCheck;

    q.push(cur);
    vis[cur.first][cur.second] = true;
    div_idx.push(edge.size());

    while (!q.empty()){
        cur = q.front(); q.pop();
        pushCheck = false;

        for (int i=0;i<4;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < N && !vis[nxt_x][nxt_y]){
                if (country[nxt_x][nxt_y] == 1){
                    q.push(make_pair(nxt_x,nxt_y));
                    vis[nxt_x][nxt_y] = true;
                }
                else {
                    if (!pushCheck){
                        edge.push_back(make_pair(cur.first,cur.second));
                        pushCheck = true;
                    }
                }
            }
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,st,dist, minDist=201;

    cin >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> country[i][j];
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (country[i][j] == 1 && !vis[i][j]){
                find_edge_bfs(N,{i,j});
            }
        }
    }

    while (div_idx.size() > 1){
        st = div_idx.front(); div_idx.pop();

        for (int i=st;i<div_idx.front();i++){
            for (int j=div_idx.front();j<(int)edge.size();j++){
                dist = abs(edge[i].first-edge[j].first) + abs(edge[i].second-edge[j].second) -1;

                if (minDist > dist){
                    minDist = dist;
                }
            }
        }
    }

    cout << minDist;

    return 0;
}
