#include <bits/stdc++.h>

using namespace std;

int maps[503][503];
bool vis[503][503];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int getPictureSize_bfs(int y, int x, pair<int,int> wall){
    queue<pair<int,int>> q;
    pair<int,int> cur_loc,nxt_loc, wall_ = {0,0};
    int pictureSize = 1;

    q.push(make_pair(y,x));
    vis[y][x] = true;

    while(!q.empty()){
        cur_loc = q.front(); q.pop();

        for (int i=0;i<4;i++){
            nxt_loc = make_pair(cur_loc.first+dy[i],cur_loc.second+dx[i]);

            if (wall_ <= nxt_loc && nxt_loc < wall && maps[nxt_loc.first][nxt_loc.second] == 1 && !vis[nxt_loc.first][nxt_loc.second]){
                q.push(nxt_loc);
                vis[nxt_loc.first][nxt_loc.second] = true;
                pictureSize++;
            }
        }
    }
    return pictureSize;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,m,pictureSize, pictures = 0, pictureSize_MX = 0;

    cin >> n >> m;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> maps[i][j];
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!vis[i][j] && maps[i][j] == 1){
                pictureSize = getPictureSize_bfs(i,j,{n,m});
                if (pictureSize_MX < pictureSize){
                    pictureSize_MX = pictureSize;
                }
                pictures++;
            }
        }
    }

    cout << pictures << '\n' << pictureSize_MX;

    return 0;
}
