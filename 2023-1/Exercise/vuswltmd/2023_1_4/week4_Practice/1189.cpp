//1189 ÄÄ¹éÈ¨
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char board[10][10];
bool vis[10][10];
int R, C, K;
pair<int, int> st;
pair<int, int> home;
int ans = 0;

void func(int x, int y, int depth) {
    if ((depth == K) && (x == home.first) && (y == home.second)) {
        ans++;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (vis[nx][ny] != 0) continue;
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (board[nx][ny] == 'T') continue;


        vis[nx][ny] = 1;
        func(nx, ny, depth + 1);
        vis[nx][ny] = 0;
    }


}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C >> K;

    st = { R - 1, 0 };
    home = { 0, C - 1 };

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    vis[st.first][st.second] = 1;
    func(st.first, st.second, 1);

    cout << ans;
}

