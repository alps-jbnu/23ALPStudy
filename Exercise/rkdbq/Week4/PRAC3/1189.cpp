#include <iostream>
#include <vector>
using namespace std;

int cnt;
char map[5][5];
bool vis[5][5];
int R, C, K;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(pair<int, int> cur, int dis) {
    if(cur.first == 0 && cur.second == C-1) {
        //cout<<dis<<"\n";
        if(dis == K) cnt++;
        return;
    }
    if(dis>K) return;
    for(int i{}; i<4; i++) {
        pair<int, int> nxt = cur;
        nxt.first += dx[i];
        nxt.second += dy[i];
        //cout<<nxt.first<<", "<<nxt.second<<", "<<dis<<"\n";

        if(nxt.first < 0 || nxt.first >= R) continue;
        if(nxt.second < 0 || nxt.second >= C) continue;
        if(vis[nxt.first][nxt.second]) continue;
        if(map[nxt.first][nxt.second] == 'T') continue;

        vis[nxt.first][nxt.second] = true;
        dfs(nxt, dis+1);
        vis[nxt.first][nxt.second] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>R>>C>>K;
    for(int i{}; i<R; i++) {
        for(int j{}; j<C; j++) {
            cin>>map[i][j];
        }
    }

    vis[R-1][0] = true;
    dfs({R-1, 0}, 1);

    cout<<cnt;

    return 0;
}