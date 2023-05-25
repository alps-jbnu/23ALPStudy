#define INF 2147483647
#define MAX 250001
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, R;
bool cows[101][101];
int board[101][101][4];
bool vis[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool is_road(pair<int, int> from, pair<int, int>to) {
    for(int i{}; i<4; i++) {
        if(board[from.first][from.second][i]==0) continue;
        for(int j{}; j<4; j++) {
            if(board[to.first][to.second][j]==0) continue;
            if(board[from.first][from.second][i] == board[to.first][to.second][j]) return true;
        }
    }
    return false;
}

int bfs(pair<int, int> st) {
    for(int i{}; i<N; i++) for(int j{}; j<N; j++) vis[i][j] = false;
    queue<pair<int, int>> q;
    vis[st.first][st.second] = true;
    q.push(st);
    while(!q.empty()) {
        auto cur{q.front()};
        q.pop();
        for(int i{}; i<4; i++) {
            auto nxt{cur};
            nxt.first += dx[i];
            nxt.second += dy[i];

            if(nxt.first<0 || nxt.first>=N || nxt.second<0 || nxt.second>=N) continue;
            if(vis[nxt.first][nxt.second]) continue;
            if(is_road(cur, nxt)) continue;

            vis[nxt.first][nxt.second] = true;
            q.push(nxt);
        }
    }
    int cnt{};
    for(int i{}; i<N; i++) {
        for(int j{}; j<N; j++) {
            if(cows[i][j] && !vis[i][j]) cnt++;
        }
    }
    return cnt;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>K>>R;
    for(int i{1}; i<=R; i++) {
        pair<int, int> from, to;
        cin>>from.first>>from.second>>to.first>>to.second;
        for(int j{}; j<4; j++) {
            if(board[from.first-1][from.second-1][j] == 0) {
                board[from.first-1][from.second-1][j] = i;
                break;
            }
        }
        for(int j{}; j<4; j++) {
            if(board[to.first-1][to.second-1][j] == 0) {
                board[to.first-1][to.second-1][j] = i;
                break;
            }
        }
    }
    for(int i{}; i<K; i++) {
        pair<int, int> cow;
        cin>>cow.first>>cow.second;
        cows[cow.first-1][cow.second-1] = true;
    }

    // for(int i{}; i<N; i++) {
    //     for(int j{}; j<N; j++) {
    //         cout<<cows[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int total{};
    for(int i{}; i<N; i++) {
        for(int j{}; j<N; j++) {
            if(!cows[i][j]) continue;
            total += bfs({i, j});
        }
    }
    cout<<total/2;

    return 0;
}