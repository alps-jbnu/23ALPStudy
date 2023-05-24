#include <bits/stdc++.h>

using namespace std;

char board[5][5];
vector<pair<int,int>> pieces;
int min_dist;
bool check[5][5], visited[5][5];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void func(int count, int dist) {
    if(min_dist <= dist) return;
    if(count == pieces.size())
    {
        for(int i = 0; i < 5; i++)
            fill(visited[i], visited[i] + 5, false);

        pair<int,int> temp;
        for (int i = 0; i < 5; ++i)
        {
            for(int j = 0; j < 5; ++j)
            {
                if(check[i][j])
                {
                    temp = make_pair(i, j);
                }
            }
        }
        queue<pair<int,int>> q;
        q.push(temp);
        visited[temp.first][temp.second] = true;
        int count_check = 0;
        while(!q.empty())
        {
            count_check++;
            auto cur = q.front(); q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                if(visited[nx][ny]) continue;
                if(check[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        if(count_check == pieces.size())
        {
            min_dist = min(min_dist, dist);
        }
        return;
    }
    for (int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(check[i][j]) continue;
            check[i][j] = true;
            func(count + 1, dist + abs(pieces[count].first - i) + abs(pieces[count].second - j));
            check[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            cin >> board[i][j];
            if(board[i][j] == '*')
                pieces.push_back(make_pair(i, j));
        }
    }
    if(pieces.size() == 1)
    {
        cout << 0; return 0;
    }
    min_dist = 26;
    func(0, 0);
    cout << min_dist;
    return 0;
}
