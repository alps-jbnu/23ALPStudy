#include<bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0, - 1,0 };
int dy[4] = { 0,1,0,-1 };
int board[5][5];
vector<int> saved;

void dfs(int x, int y, int n, int len) {
    if (len == 6) {
        saved.push_back(n);
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
            continue;

        dfs(nx, ny, n * 10 + board[nx][ny], len + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, 0, 0);
        }
    }
    
    sort(saved.begin(), saved.end());
    saved.erase(unique(saved.begin(), saved.end()), saved.end());

    cout << saved.size();

    return 0;
}