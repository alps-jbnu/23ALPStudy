#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int board[201][201];
int vis[201][201];
queue<pair<int, int>> Q;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

void visInit() {
    for(int i{}; i<201; i++) {
        for(int j{}; j<201; j++) {
            vis[i][j] = -1;
        }
    }
}

void bfs() {
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int i{}; i<6; i++) {
            auto nxt = cur;
            nxt.first += dx[i];
            nxt.second += dy[i];

            if(nxt.first < 0 || nxt.first >= N) continue;
            if(nxt.second < 0 || nxt.second >= N) continue;
            if(vis[nxt.first][nxt.second] != -1) continue;

            vis[nxt.first][nxt.second] = vis[cur.first][cur.second]+1;
            Q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    visInit();

    cin>>N;
    int r1,c1, r2,c2;
    cin>>r1>>c1>>r2>>c2;

    Q.push({r1, c1});
    vis[r1][c1] = 0;
    bfs();
    cout<<vis[r2][c2];

    return 0;
}