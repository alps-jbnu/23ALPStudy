#include <bits/stdc++.h>

using namespace std;

char board[100][10];
bool check[100][10];

int dx[4] = {1, 0, -1,0};
int dy[4] = {0, 1, 0,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> board[i][j];
        }
    }

    while(true)
    {
        bool checkAll = true;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(board[i][j] != '0')
                {
                    vector<pair<int,int>> v;
                    v.push_back(make_pair(i, j));
                    queue<pair<int,int>> q;
                    q.push(v[0]);
                    check[i][j] = true;
                    while(!q.empty())
                    {
                        auto cur = q.front(); q.pop();
                        for(int k = 0; k < 4; k++)
                        {
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];
                            if(nx < 0 || ny < 0 || nx >= N || ny >= 10) continue;
                            if(check[nx][ny]) continue;
                            if(board[nx][ny] != board[i][j]) continue;
                            check[nx][ny] = true;
                            v.push_back(make_pair(nx, ny));
                            q.push(make_pair(nx, ny));
                        }
                    }
                    if(v.size() >= K)
                    {
                        checkAll = false;
                        for(int k = 0; k < v.size(); k++)
                        {
                            board[v[k].first][v[k].second] = '0';
                        }
                    }
                }
            }
        }
        for(int i = N - 2; i >= 0; i--)
        {
            for (int j = 0; j < 10; j++)
            {
                if(board[i][j] != '0')
                {
                    int x = i + 1;
                    while(x < N && board[x][j] == '0')
                    {
                        board[x][j] = board[x - 1][j];
                        board[x - 1][j] = '0';
                        x++;
                    }
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            fill(check[i], check[i] + 10, false);
        }
        if(checkAll)
            break;
    }
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}
