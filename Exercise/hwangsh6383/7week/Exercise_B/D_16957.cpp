#include <bits/stdc++.h>

using namespace std;

int board[500][500];
int answer[500][500];

int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C; cin >> R >> C;
    vector<pair<int,pair<int,int>>> v;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            v.push_back(make_pair(board[i][j], make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());

    for(int i = v.size() - 1; i >= 0; i--)
    {
        pair<int,pair<int,int>> temp = v[i];
        for(int j = 0; j < 8; j++)
        {
            int nx = v[i].second.first + dx[j];
            int ny = v[i].second.second + dy[j];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if(temp.first > board[nx][ny])
                temp = make_pair(board[nx][ny], make_pair(nx, ny));
        }
        if(temp.first != v[i].first)
        {
            answer[temp.second.first][temp.second.second] += answer[v[i].second.first][v[i].second.second] + 1;
            answer[v[i].second.first][v[i].second.second] = 0;
        }
        else
        {
            answer[temp.second.first][temp.second.second]++;
        }
    }

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
