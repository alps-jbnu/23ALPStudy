#include <bits/stdc++.h>

using namespace std;

char board[1000][1000];
bool check[1000][1000];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    int answer1 = 0, answer2 = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(board[i][j] == '#' && !check[i][j])
            {
                int area = 0, perimeter = 0;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                check[i][j] = true;
                while(!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    area++;
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if(nx < 0 || ny < 0 || nx >= N || ny >= N)
                        {
                            perimeter++;
                            continue;
                        }
                        if(board[nx][ny] == '.')
                        {
                            perimeter++;
                            continue;
                        }
                        if(check[nx][ny]) continue;
                        check[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
                if(answer1 < area)
                {
                    answer1 = area; answer2 = perimeter;
                }
                else if(answer1 == area)
                    answer2 = min(answer2, perimeter);
            }
        }
    }
    cout << answer1 << ' ' << answer2;
    return 0;
}
