#include <bits/stdc++.h>

using namespace std;

int R, C, K;
char board[6][6];
int cnt[26];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void visit_home(int x, int y, int distance, vector<vector<bool>> vst) {
    if (x == 1 && y == C) {
        cnt[distance] += 1;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nxt_x = x + dx[i];
        int nxt_y = y + dy[i];
        if (nxt_x < 1 || nxt_x > R || nxt_y < 1 || nxt_y > C) continue;
        if (vst[nxt_x][nxt_y]) continue;
        if (board[nxt_x][nxt_y] == 'T') continue;
        vst[nxt_x][nxt_y] = true;
        visit_home(nxt_x, nxt_y, distance + 1, vst);
        vst[nxt_x][nxt_y] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> K;
    vector<vector<bool>> vst;
    vst.emplace_back();
    for (int i = 1; i <= R; i++) {
        vst.emplace_back();
        vst[i].emplace_back(false);
        for (int j = 1; j <= C; j++) {
            cin >> board[i][j];
            vst[i].emplace_back(false);
        }
    }
    vst[R][1] = true;
    visit_home(R, 1, 1, vst);
    cout << cnt[K];
    return 0;
}
