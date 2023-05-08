#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, H, W;
pair<int, int> S, F;
int map[1001][1001];
int visited[1001][1001];
queue<pair<int, int>> Q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void init() {
    for(int i{1}; i<=N; i++) {
        for(int j{1}; j<=M; j++) {
            visited[i][j] = -1;
        }
    }
}

void wall_check(pair<int, int> cur) {
    for(int i{cur.first}; i>=cur.first-H+1; i--) {
        for(int j{cur.second}; j>=cur.second-W+1; j--) {
            if(i<=0 || i>N || j<=0 || j>M) continue;
            map[i][j] = 2;
        }
    }
}

void bfs() {
    visited[S.first][S.second] = 0;
    Q.push(S);

    while(!Q.empty() && visited[F.first][F.second] == -1) {
        auto cur{Q.front()};
        Q.pop();
        for(int i{}; i<4; i++) {
            auto nxt{cur};
            nxt.first += dx[i];
            nxt.second += dy[i];

            if(nxt.first <= 0 || nxt.first > N || nxt.second <= 0 || nxt.second > M) continue;
            if((nxt.first + H - 1) <= 0 || (nxt.first + H - 1) > N || (nxt.second + W - 1) <= 0 || (nxt.second + W - 1) > M) continue;
            if(visited[nxt.first][nxt.second] != -1) continue;
            if(map[nxt.first][nxt.second] != 0) continue;

            visited[nxt.first][nxt.second] = visited[cur.first][cur.second] + 1;
            Q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    init();
    for(int i{1}; i<=N; i++) {
        for(int j{1}; j<=M; j++) {
            cin>>map[i][j];
        }
    }
    cin>>H>>W>>S.first>>S.second>>F.first>>F.second;

    for(int i{1}; i<=N; i++) {
        for(int j{1}; j<=M; j++) {
            if(map[i][j] == 1) wall_check({i, j});
        }
    }

    // for(int i{1}; i<=N; i++) {
    //     for(int j{1}; j<=M; j++) {
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    bfs();
    cout<<visited[F.first][F.second];
    
    return 0;
}