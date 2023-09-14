#include <bits/stdc++.h>

using namespace std;

int N;
bool board[101][101];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, d, g; cin >> x >> y >> d >> g;
        vector<pair<pair<int, int>, int>> curve;
        curve.emplace_back(make_pair(y, x), d);
        board[y][x] = true; board[y + dx[d]][x + dy[d]] = true;
        while (g--) {
            int curve_size = curve.size();
            auto last_line = curve[curve_size - 1];
            int new_x = last_line.first.first + dx[last_line.second];
            int new_y = last_line.first.second + dy[last_line.second];
            for (int j = curve_size - 1; j >= 0; j--) {
                auto p = curve[j];
                int new_d = (p.second + 1) % 4;
                curve.emplace_back(make_pair(new_x, new_y), new_d);
                new_x += dx[new_d]; new_y += dy[new_d];
                board[new_x][new_y] = true;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) {
                answer += 1;
            }
        }
    }
    cout << answer;
    return 0;
}
