#include <bits/stdc++.h>

using namespace std;

pair<int,int> board[21][21];
vector<int> dir;
int prior[401][5][5];

int dx[4] = {-1, 1,0,0};
int dy[4] = {0,0, -1,1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, k; cin >> N >> M >> k;
    queue<pair<int,int>> q;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int x; cin >> x;
            if(x)
            {
                board[i][j] = make_pair(k,x);
                q.push(make_pair(i, j));
            }
        }
    }
    dir.push_back(0);
    for(int i = 1; i <= M; i++)
    {
        int d; cin >> d;
        dir.push_back(d);
    }
    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            for(int m = 1; m <= 4; m++)
            {
                cin >> prior[i][j][m];
                prior[i][j][m]--;
            }
        }
    }
    int answer = 0;
    while(q.size() != 1)
    {
        answer++;
        if(answer > 1000)
        {
            answer = -1;
            break;
        }
        map<pair<int,int>, int> m;
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            int x = board[cur.first][cur.second].second; // shark num
            bool cannotgo = true;
            for(int i = 1; i <= 4; i++)
            {
                int p = prior[x][dir[x]][i];
                int nx = cur.first + dx[p];
                int ny = cur.second + dy[p];
                if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                if(board[nx][ny].first == 0)
                {
                    if(m.find(make_pair(nx, ny)) != m.end())
                    {
                        if(m[make_pair(nx, ny)] > x)
                            m[make_pair(nx, ny)] = x;
                    }
                    else
                        m[make_pair(nx, ny)] = x;
                    dir[x] = p + 1;
                    cannotgo = false;
                    break;
                }
            }
            if(cannotgo)
            {
                for(int i = 1; i <= 4; i++)
                {
                    int p = prior[x][dir[x]][i];
                    int nx = cur.first + dx[p];
                    int ny = cur.second + dy[p];
                    if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                    if(board[nx][ny].second == board[cur.first][cur.second].second)
                    {
                        m[make_pair(nx, ny)] = x;
                        dir[x] = p + 1;
                        break;
                    }
                }
            }
        }
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(m.find(make_pair(i, j)) != m.end())
                {
                    board[i][j].first = k;
                    board[i][j].second = m[make_pair(i,j)];
                    q.push(make_pair(i, j));
                }
                else
                {
                    if(board[i][j].first > 0)
                    {
                        board[i][j].first--;
                        if(!board[i][j].first)
                            board[i][j].second = 0;
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}
