#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, k;
char board[105][15];
bool visited[105][15];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> q;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }
    while (true) {
        for (int i = 0; i < 100; i++) {
            fill(visited[i], visited[i] + 10, false);
        }

        bool flag = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (visited[i][j] || board[i][j] == '0') 
                    continue;

                vector<pair<int, int>> v;

                q.emplace(i, j);
                visited[i][j] = true;
                char color = board[i][j];

                while (!q.empty()) {
                    auto cur = q.front(); 
                    q.pop();
                    v.emplace_back(cur.first, cur.second);

                    for (int k = 0; k < 4; k++) {
                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];

                        if (x < 0 || x >= n || y < 0 || y >= 10)
                            continue;
                        if (visited[x][y] || board[x][y] != color) 
                            continue;

                        visited[x][y] = true;
                        q.emplace(x, y);
                    }
                }
                if (v.size() >= k) {
                    flag = true;
                    for (auto c : v) {
                        board[c.first][c.second] = '0';
                    }
                }
            }
        }

        for (int j = 0; j < 10; j++) {
            queue<char> gravity;

            for (int i = n - 1; i >= 0; i--) {
                if (board[i][j] != '0') gravity.emplace(board[i][j]);
            }

            int i = n - 1;

            while (!gravity.empty()) {
                auto cur = gravity.front(); gravity.pop();
                board[i--][j] = cur;
            }

            while (i >= 0) {
                board[i--][j] = '0';
            }
        }

        if (!flag) 
            break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}