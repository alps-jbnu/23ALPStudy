#include <bits/stdc++.h>

using namespace std;

int city[103][103];
int vis[103][103];
int dx[4] = {0, 0, 1,-1};
int dy[4] = {1,-1, 0, 0};

void safe_bfs(int N, pair<int,int> cur, int H){
    queue<pair<int,int>> q;

    int nxt_x,nxt_y;

    q.push(cur);
    vis[cur.first][cur.second] = H;

    while (!q.empty()){
        cur = q.front(); q.pop();

        for (int i=0;i<4;i++){
            nxt_x = cur.first + dx[i];
            nxt_y = cur.second + dy[i];

            if (0 <= nxt_x && nxt_x < N && 0 <= nxt_y && nxt_y < N && city[nxt_x][nxt_y] > H && vis[nxt_x][nxt_y] != H){
                q.push(make_pair(nxt_x,nxt_y));
                vis[nxt_x][nxt_y] = H;
            }
        }
    }

    return ;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, safe=0, safeMX=1, maxH=0, minH=103;

    cin >> N;

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> city[i][j];

            if (city[i][j] > maxH){
                maxH = city[i][j];
            }

            if (city[i][j] < minH){
                minH = city[i][j];
            }
        }
    }

    for (int h=minH;h<maxH;h++){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (city[i][j] > h && vis[i][j] != h){
                    safe_bfs(N,{i,j},h);
                    safe++;
                }
            }
        }

        if (safe > safeMX){
            safeMX = safe;
        }
        safe = 0;
    }

    cout << safeMX;

    return 0;
}
