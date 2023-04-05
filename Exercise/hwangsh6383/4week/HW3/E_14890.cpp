#include <bits/stdc++.h>

using namespace std;

int board[100][100];
bool check[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L; cin >> N >> L;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - 1; j++)
        {
            if(j + 1 < N && board[i][j] + 1 == board[i][j + 1])
            {
                if(j - L + 1 < 0) break;
                for(int k = j; k > j - L + 1; k--)
                {
                    if(board[i][k] != board[i][k - 1] || check[i][k - 1])
                    {
                        j = N; break;
                    }
                    check[i][k - 1] = check[i][k] = true;
                }
            }
            else if(j + 1 < N && board[i][j] - 1 == board[i][j + 1])
            {
                if(j + L > N) break;
                for(int k = j + 1; k < j + L; k++)
                {
                    if(board[i][k] != board[i][k + 1] || check[i][k + 1])
                    {
                        j = N; break;
                    }
                    check[i][k] = check[i][k + 1] = true;
                }
                if(j + L + 1 < N && board[i][j + L] < board[i][j + L + 1]) break;
                j = j + L - 1;
            }
            else if(j + 1 < N && board[i][j] == board[i][j + 1])
            {}
            else
            {
                break;
            }
            if(j == N - 2)
            {
                answer++;
            }
        }
    }
    for(int i = 0; i < N; i++)
        fill(check[i], check[i] + N, 0);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - 1; j++)
        {
            if(j + 1 < N && board[j][i] + 1 == board[j + 1][i])
            {
                if(j - L + 1 < 0) break;
                for(int k = j; k > j - L + 1; k--)
                {
                    if(board[k][i] != board[k - 1][i] || check[k - 1][i])
                    {
                        j = N; break;
                    }
                    check[k][i] = check[k - 1][i] = true;
                }
            }
            else if(j + 1 < N && board[j][i] - 1 == board[j + 1][i])
            {
                if(j + L > N) break;
                for(int k = j + 1; k < j + L; k++)
                {
                    if(board[k][i] != board[k + 1][i] || check[k + 1][i])
                    {
                        j = N; break;
                    }
                    check[k][i] = check[k + 1][i] = true;
                }
                if(j + L + 1 < N && board[j + L][i] < board[j + L + 1][i]) break;
                j = j + L - 1;
            }
            else if(j + 1 < N && board[j][i] == board[j + 1][i])
            {}
            else
            {
                break;
            }
            if(j == N - 2)
            {
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}
