#include <bits/stdc++.h>
using namespace std;

int board[100][100];
vector<int> vecArr[200];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            vecArr[row].push_back(board[row][col]);
        }
    }
    for (int col = 0; col < N; col++)
    {
        for (int row = 0; row < N; row++)
        {
            vecArr[col + N].push_back(board[row][col]);
        }
    }

    for (int i = 0; i < 2 * N; i++)
    {
        bool stop = false;
        int sameHeight = 1;
        for (int j = 0; j < vecArr[i].size() - 1; j++)
        {
            if (vecArr[i][j] == vecArr[i][j + 1])
            {
                sameHeight++;
                continue;
            }

            else if (vecArr[i][j] == vecArr[i][j + 1] + 1)
            {
                int cnt = 1;
                bool chk = true;
                for (int k = 1; k < L; k++)
                {
                    if (vecArr[i][j + k] == vecArr[i][j + k + 1])
                    {
                        cnt++;
                    }
                    else
                    {
                        chk = false;
                        break;
                    }
                }
                if (chk == false)
                {
                    stop = true;
                    break;
                }
                else
                {
                    if (cnt == L)
                    {
                        j += cnt - 1;
                        sameHeight = 0;
                    }
                }
            }

            else if (vecArr[i][j] + 1 == vecArr[i][j + 1])
            {
                if (sameHeight >= L)
                {
                    sameHeight = 1;
                    continue;
                }
                else
                {
                    stop = true;
                    break;
                }
            }
            else if (abs(vecArr[i][j] - vecArr[i][j + 1]) >= 2)
            {
                stop = true;
                break;
            }
        }
        if (!stop)
        {
            ans++;
            // cout << i << "\n";
        }
    }
    cout << ans;
}