#include <bits/stdc++.h>

using namespace std;

int N, K;
int virus[201][201];
vector<pair<int, int>> virus_list[1001];
int S, X, Y;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> virus[i][j];
            if (virus[i][j]) {
                virus_list[virus[i][j]].emplace_back(i, j);
            }
        }
    }
    cin >> S >> X >> Y;
    while (S-- && !virus[X][Y]) {
        for (int i = 1; i <= K; i++) {
            vector<pair<int, int>> add_list;
            for (auto p : virus_list[i]) {
                for (int j = 0; j < 4; j++) {
                    int x = p.first + dx[j];
                    int y = p.second + dy[j];
                    if (x < 1 || x > N || y < 1 || y > N) continue;
                    if (virus[x][y]) continue;
                    add_list.emplace_back(x, y);
                    virus[x][y] = i;
                }
            }
            for (auto p : add_list) {
                virus_list[i].push_back(p);
            }
        }
    }
    cout << virus[X][Y];
    return 0;
}
