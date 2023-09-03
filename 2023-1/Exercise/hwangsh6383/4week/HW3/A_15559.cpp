#include <bits/stdc++.h>

using namespace std;

int parent[1000001];
char board[1000][1000];
int answer;

int _find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = _find(parent[x]);
}

bool _union(int a, int b) {
    a = _find(a);
    b = _find(b);
    if(a == b) return true;
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
    answer--;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    answer = N * M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            parent[i * M + j + 1] = i * M + j + 1;
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            queue<pair<int,int>> q;
            q.push(make_pair(i, j));
            while(!q.empty())
            {
                auto cur = q.front(); q.pop();
                if(board[cur.first][cur.second] == 'N')
                {
                    if(!_union(cur.first * M + cur.second + 1, (cur.first - 1) * M + cur.second + 1))
                    {
                        q.push(make_pair(cur.first - 1, cur.second));
                    }
                }
                else if(board[cur.first][cur.second] == 'W')
                {
                    if(!_union(cur.first * M + cur.second + 1, cur.first * M + cur.second))
                    {
                        q.push(make_pair(cur.first, cur.second - 1));
                    }
                }
                else if(board[cur.first][cur.second] == 'E')
                {
                    if(!_union(cur.first * M + cur.second + 1, cur.first * M + cur.second + 2))
                    {
                        q.push(make_pair(cur.first, cur.second + 1));
                    }
                }
                else
                {
                    if(!_union(cur.first * M + cur.second + 1, (cur.first + 1) * M + cur.second + 1))
                    {
                        q.push(make_pair(cur.first + 1, cur.second));
                    }
                }
            }
        }
    }
    cout << answer;
    return 0;
}
