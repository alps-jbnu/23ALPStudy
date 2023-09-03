#include <bits/stdc++.h>
using namespace std;

int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[9] = {-1, 0, 1, 0, -1, 1, -1, 0, 1};

int r, c;
int board[505][505];
int dp[505][505];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }
}