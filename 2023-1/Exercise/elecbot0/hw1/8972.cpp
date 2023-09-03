#include <bits/stdc++.h>

using namespace std;

int R, C;
char board[101][101];
string text;
pair<int, int> jongsu;
vector<pair<int, int>> crazy;

int dx[10] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
int dy[10] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'I') {
                jongsu = make_pair(i, j);
            } else if (board[i][j] == 'R') {
                crazy.emplace_back(i, j);
            }
        }
    }
    cin >> text;
    int X = 0;
    bool game_end = false;
    for (char c : text) {
        X += 1;
        int x = jongsu.first + dx[c - '0'];
        int y = jongsu.second + dy[c - '0'];
        for (int i = 0; i < crazy.size(); i++) {
            if (crazy[i].first == x && crazy[i].second == y) {
                game_end = true;
                break;
            }
        }
        if (game_end) break;
        jongsu = make_pair(x, y);
        for (int i = 0; i < crazy.size(); i++) {
            int crazy_x = crazy[i].first;
            int crazy_y = crazy[i].second;
            int min_dis = INT_MAX;
            int move_dir = 0;
            for (int j = 1; j <= 9; j++) {
                int new_crazy_x = crazy_x + dx[j];
                int new_crazy_y = crazy_y + dy[j];
                int dis = abs(x - new_crazy_x) + abs(y - new_crazy_y);
                if (min_dis > dis) {
                    min_dis = dis;
                    move_dir = j;
                }
            }
            int new_crazy_x = crazy_x + dx[move_dir];
            int new_crazy_y = crazy_y + dy[move_dir];
            if (new_crazy_x == jongsu.first && new_crazy_y == jongsu.second) {
                game_end = true;
                break;
            }
            crazy[i] = make_pair(new_crazy_x, new_crazy_y);
        }
        if (game_end) break;
        bool remove[10001] = {};
        sort(crazy.begin(), crazy.end());
        for (int i = 0; i < crazy.size(); i++) {
            pair<int, int> prev = make_pair(-1, -1);
            pair<int, int> nxt = make_pair(-1, -1);
            if (i > 0) prev = crazy[i - 1];
            if (i < crazy.size() - 1) nxt = crazy[i + 1];
            if ((prev.first == crazy[i].first && prev.second == crazy[i].second) ||
                (nxt.first == crazy[i].first && nxt.second == crazy[i].second)) {
                remove[i] = true;
            }
        }
        int num = 0;
        for (auto it = crazy.begin(); it != crazy.end();) {
            if (remove[num++]) {
                board[it->first][it->second] = '.';
                it = crazy.erase(it);
            } else {
                it++;
            }
        }
    }
    if (game_end) {
        cout << "kraj " << X;
    } else {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j] = '.';
            }
        }
        board[jongsu.first][jongsu.second] = 'I';
        for (int i = 0; i < crazy.size(); i++) {
            board[crazy[i].first][crazy[i].second] = 'R';
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << board[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
