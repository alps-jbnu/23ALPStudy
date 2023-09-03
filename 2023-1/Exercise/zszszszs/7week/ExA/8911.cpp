#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        bool board[1005][1005];
        for (int a = 0; a < 1005; a++)
        {
            for (int b = 0; b < 1005; b++)
            {
                board[a][b] = false;
            }
        }
        int x = 500;
        int y = 500;
        int dir = 0;

        board[x][y] = true;
        for (int a = 0; a < s.size(); a++)
        {
            if (s[a] == 'F')
            {
                x = x + dx[dir];
                y = y + dy[dir];
            }
            else if (s[a] == 'B')
            {
                x = x - dx[dir];
                y = y - dy[dir];
            }
            else if (s[a] == 'L')
            {
                dir = (dir - 1 + 4) % 4;
            }
            else if (s[a] == 'R')
            {
                dir = (dir + 1) % 4;
            }
            board[x][y] = true;
        }

        int min_x = 0x7f7f7f;
        int min_y = 0x7f7f7f;
        int max_x = 0;
        int max_y = 0;
        for (int j = 0; j < 1005; j++)
        {
            for (int q = 0; q < 1005; q++)
            {
                if (board[j][q] == true)
                {

                    if (j <= min_x)
                    {
                        min_x = j;
                    }
                    if (q <= min_y)
                    {
                        min_y = q;
                    }

                    if (j >= max_x)
                    {
                        max_x = j;
                    }
                    if (q >= max_y)
                    {
                        max_y = q;
                    }
                }
            }
        }
        cout << (max_x - min_x) * (max_y - min_y) << '\n';
    }
}