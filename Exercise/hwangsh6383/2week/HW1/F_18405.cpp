#include <bits/stdc++.h>

using namespace std;

int board[200][200];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   int N, K; cin >> N >> K;
   priority_queue<pair<int,pair<int,int>>,
                    vector<pair<int,pair<int,int>>>,
                            greater<pair<int,pair<int,int>>>> pq;
   for(int i = 0; i < N; i++)
   {
       for(int j = 0; j < N; j++)
       {
            cin >> board[i][j];
            if(board[i][j] != 0)
                pq.push(make_pair(board[i][j], make_pair(i, j)));
       }
   }
   int S, X, Y; cin >> S >> X >> Y;
   while(S--)
   {
       queue<pair<int, pair<int,int>>> q;
       while(!pq.empty())
       {
           q.push(pq.top()); pq.pop();
       }
       while(!q.empty())
       {
           auto cur = q.front(); q.pop();
           for(int i = 0; i < 4; i++)
           {
               int nx = cur.second.first + dx[i];
               int ny = cur.second.second + dy[i];
               if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
               if(board[nx][ny] > 0) continue;
               board[nx][ny] = cur.first;
               pq.push(make_pair(cur.first, make_pair(nx, ny)));
           }
       }
   }
   cout << board[X - 1][Y - 1];
    return 0;
}
