#include <bits/stdc++.h>
#define pii pair<int, int>
const int MAX = 200 + 1;
using namespace std;

int N;
int arr[MAX][MAX];
bool Visited[MAX][MAX];
int dir[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, +2}, {2, -1}, {2, 1} };

queue<pii> q;

int main()
{
    cin >> N;
    
    int r1, c1, r2, c2;
    for(int i = 0; i < N; i++)
    {
        
        cin >> r1 >> c1 >> r2 >> c2;
    }
    
    arr[r1][c1] = 0;
    Visited[r1][c1] = 1;
    q.push({ r1, c1 });
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i = 0; i < 6; i++)
        {
            int dx = cx + dir[i][0];
            int dy = cy + dir[i][1];
            
            if(dx < 0 || dy < 0 || dx > N || dy > N) continue;
            
            if(!Visited[dx][dy])
            {
                Visited[dx][dy] = 1;
                arr[dx][dy] = arr[cx][cy] + 1;
                
                q.push({ dx, dy });
            }
        }
    }
    
    if(!arr[r2][c2]) cout << -1;
    else cout << arr[r2][c2];
    
    return 0;
}