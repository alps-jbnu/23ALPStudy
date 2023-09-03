#include <bits/stdc++.h>

using namespace std;

int N, M, present_cnt, vst_num;
char board[1001][1001];
int vst_cnt[1001][1001];

pair<int, int> get_move(char c) {
    if (c == 'N') return make_pair(-1, 0);
    else if (c == 'S') return make_pair(1, 0);
    else if (c == 'W') return make_pair(0, -1);
    else if (c == 'E') return make_pair(0, 1);
    return make_pair(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (vst_cnt[i][j] > 0) continue;
            pair<int, int> cur_loc = make_pair(i, j);
            vst_cnt[i][j] = ++vst_num;
            while (true) {
                auto move = get_move(board[cur_loc.first][cur_loc.second]);
                int nxt_x = cur_loc.first + move.first;
                int nxt_y = cur_loc.second + move.second;
                if (nxt_x < 1 || nxt_x > N || nxt_y < 1 || nxt_y > M) break;
                if (vst_cnt[nxt_x][nxt_y] > 0) {
                    if (vst_cnt[nxt_x][nxt_y] == vst_num) {
                        present_cnt += 1;
                    }
                    break;
                }
                cur_loc = make_pair(nxt_x, nxt_y);
                vst_cnt[nxt_x][nxt_y] = vst_num;
            }
        }
    }
    cout << present_cnt;
    return 0;
}
