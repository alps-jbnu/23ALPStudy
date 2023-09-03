#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int W, H;

int dx_odd[6] = {0, 0, 1, -1, 1, 1};
int dy_odd[6] = {1, -1, 0, 0, 1, -1};
int dx_even[6] = {0, 0, 1, -1, -1, -1};
int dy_even[6] = {1, -1, 0, 0, -1, 1};

int board[101][101];
int vis[101][101];

bool bfs(pair<int, int> st) {
    queue<pair<int, int>> q;
    vis[st.first][st.second] = true;
    q.push(st);
    while(!q.empty()) {
        auto cur{q.front()};
        q.pop();
        for(int i{}; i<6; i++) {
            if(cur.first%2 == 1) {
                auto nxt{cur};
                nxt.first += dy_odd[i];
                nxt.second += dx_odd[i];

                if(nxt.first<=0 || nxt.first>H || nxt.second<=0 || nxt.second>W) return false;
                if(board[nxt.first][nxt.second] == -1) return false;
                if(board[nxt.first][nxt.second] == 1) continue;
                if(vis[nxt.first][nxt.second]) continue;
                vis[nxt.first][nxt.second] = true;
                q.push(nxt);
            }
            else {
                auto nxt{cur};
                nxt.first += dy_even[i];
                nxt.second += dx_even[i];

                if(nxt.first<=0 || nxt.first>H || nxt.second<=0 || nxt.second>W) return false;
                if(board[nxt.first][nxt.second] == -1) return false;
                if(board[nxt.first][nxt.second] == 1) continue;
                if(vis[nxt.first][nxt.second]) continue;
                vis[nxt.first][nxt.second] = true;
                q.push(nxt);
            }
        }
    }
    return true;
}

int wall_of(pair<int, int> cur) {
    int ret{};
    if(cur.first%2 == 1) {
        for(int i{}; i<6; i++) {
            auto nxt{cur};
            nxt.first += dy_odd[i];
            nxt.second += dx_odd[i];

            if(nxt.first<=0 || nxt.first>H || nxt.second<=0 || nxt.second>W) ret++;
            else if(board[nxt.first][nxt.second] == -1) ret++;
        }
    }
    else {
        for(int i{}; i<6; i++) {
            auto nxt{cur};
            nxt.first += dy_even[i];
            nxt.second += dx_even[i];

            if(nxt.first<=0 || nxt.first>H || nxt.second<=0 || nxt.second>W) ret++;
            else if(board[nxt.first][nxt.second] == -1) ret++;
        }
    }
    // cout<<"x: "<<cur.second<<", y: "<<cur.first<<"\n";
    // cout<<ret<<"\n";
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>W>>H;
    for(int i{1}; i<=H; i++) {
        for(int j{1}; j<=W; j++) {
            cin>>board[i][j];
        }
    }

    int ans{};
    for(int i{1}; i<=H; i++) {
        for(int j{1}; j<=W; j++) {
            if(board[i][j] != 0) continue;
            if(bfs({i, j})) {
                for(int k{1}; k<=H; k++) {
                    for(int l{1}; l<=W; l++) {
                        if(vis[k][l]) board[k][l] = 1;
                        vis[k][l] = false;
                    }
                }
            }
            else {
                for(int k{1}; k<=H; k++) {
                    for(int l{1}; l<=W; l++) {
                        if(vis[k][l]) board[k][l] = -1;
                        vis[k][l] = false;
                    }
                }
            }
        }
    }

    // cout<<"\n";
    // for(int i{1}; i<=H; i++) {
    //     for(int j{1}; j<=W; j++) {
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";

    for(int i{1}; i<=H; i++) {
        for(int j{1}; j<=W; j++) {
            if(board[i][j] == -1) continue;
            ans += wall_of({i, j});
        }
    }
    cout<<ans<<"\n";

    return 0;
}