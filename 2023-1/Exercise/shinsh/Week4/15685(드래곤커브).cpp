#include<bits/stdc++.h>
using namespace std;

int n;
int x, y, d, g, cnt;
int board[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int> spin;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {
        spin.clear();
        cin >> x >> y >> d >> g;

        board[x][y] = 1;

        x += dx[d];
        y += dy[d];
        board[x][y] = 1;
        spin.push_back(d);

        while (g--) {
            int size = spin.size();

            for (int i = size - 1; i >= 0; i--) {
                int temp = (spin[i]+1) % 4;
                x += dx[temp];
                y += dy[temp];
                board[x][y] = 1;
                spin.push_back(temp);
            }
        }
    }

    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < 105; j++) {
            if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] && board[i + 1][j] == 1)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}