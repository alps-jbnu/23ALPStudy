#include <bits/stdc++.h>

using namespace std;

int N, K;
char board[100][10];
bool vst[100][10];
queue<pair<int, int>> q;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }
    while (true) {
        for (int i = 0; i < 100; i++) {
            fill(vst[i], vst[i] + 10, false);
        }
        bool change = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 10; j++) {
                if (vst[i][j] || board[i][j] == '0') continue;
                vector<pair<int, int>> v;
                q.emplace(i, j);
                vst[i][j] = true;
                char color = board[i][j];
                while (!q.empty()) {
                    auto cur = q.front(); q.pop();
                    v.emplace_back(cur.first, cur.second);
                    for (int k = 0; k < 4; k++) {
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];
                        if (x < 0 || x >= N || y < 0 || y >= 10) continue;
                        if (vst[x][y] || board[x][y] != color) continue;
                        vst[x][y] = true;
                        q.emplace(x, y);
                    }
                }
                if (v.size() >= K) {
                    change = true;
                    for (auto p : v) {
                        board[p.first][p.second] = '0';
                    }
                }
            }
        }
        for (int j = 0; j < 10; j++) {
            queue<char> gravity_q;
            for (int i = N - 1; i >= 0; i--) {
                if (board[i][j] != '0') gravity_q.emplace(board[i][j]);
            }
            int i = N - 1;
            while (!gravity_q.empty()) {
                auto cur = gravity_q.front(); gravity_q.pop();
                board[i--][j] = cur;
            }
            while (i >= 0) {
                board[i--][j] = '0';
            }
        }
        if (!change) break;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}
