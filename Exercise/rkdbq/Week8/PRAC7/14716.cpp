#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int N, M;
bool board[251][251];
bool vis[251][251];
queue<pair<int, int>> q;
int ans;

int bfs(pair<int, int> st) {
    if(!board[st.first][st.second]) return 0;
    if(vis[st.first][st.second]) return 0;
    q.push(st);
    while(!q.empty()) {
        auto cur{q.front()};
        q.pop();
        for(int i{}; i<8; i++) {
            auto nxt{cur};
            nxt.first+=dx[i];
            nxt.second+=dy[i];

            if(nxt.first<0 || nxt.first>=N || nxt.second<0 || nxt.second>=M) continue;
            if(!board[nxt.first][nxt.second]) continue;
            if(vis[nxt.first][nxt.second]) continue;
            vis[nxt.first][nxt.second] = true;
            q.push(nxt);
        }
    }
    return 1;
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
    for(int i{}; i<N; i++) {
        for(int j{}; j<M; j++) {
            ans += bfs({i, j});
        }
    }
    cout<<ans;

    return 0;
}