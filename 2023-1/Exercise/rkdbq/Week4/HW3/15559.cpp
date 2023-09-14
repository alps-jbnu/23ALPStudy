#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, M;

int cnt;
int visited[1001][1001];
char board[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(pair<int ,int> cur, int level) {
    auto nxt = cur;
    char dir = board[cur.first][cur.second];

    int nd = 0;
    if(dir == 'E') nd = 0;
    else if(dir == 'W') nd = 1;
    else if(dir == 'S') nd = 2;
    else nd = 3;
    
    nxt.first += dx[nd];
    nxt.second += dy[nd];

    if(visited[nxt.first][nxt.second] != 0) {
        if(visited[nxt.first][nxt.second] == level) {
            cnt++;
            return;
        }
        else return;
    }
    visited[nxt.first][nxt.second] = level;
    dfs(nxt, level);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    
    for(int i{}; i<N; i++) {
        for(int j{}; j<M; j++) {
            cin>>board[i][j];
        }
    }

    int level = 1;
    for(int i{}; i<N; i++) {
        for(int j{}; j<M; j++) {
            if(visited[i][j]) continue;
            visited[i][j] = level;
            dfs({i, j}, level++);
        }
    }

    cout<<cnt;
}