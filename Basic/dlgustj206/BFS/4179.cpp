#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

string maze[1001];
int fire[1001][1001];
int jh[1001][1001];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(int, int);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        fill(fire[i], fire[i]+m, -1);
        fill(jh[i], jh[i]+m, -1);    
    } 
    for(int i = 0; i < n; i++)
        cin >> maze[i];  
    
    bfs(n, m);
}

int bfs(int n, int m){
    queue<pair<int,int> > Q1;
    queue<pair<int,int> > Q2;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 'F'){
                Q1.push({i,j});
                fire[i][j] = 0;        
            }
            if(maze[i][j] == 'J'){
            Q2.push({i,j});
            jh[i][j] = 0;
            }
        }
    }
    
    // 불에 대한 BFS
    while(!Q1.empty()){
        auto cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(fire[nx][ny] >= 0 || maze[nx][ny] == '#') continue; 
            fire[nx][ny] = fire[cur.X][cur.Y]+1;
            Q1.push({nx,ny});
        }
    }

    // 지훈이에 대한 BFS
    while(!Q2.empty()){
        auto cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << jh[cur.X][cur.Y]+1 << '\n';
                return 0;
            }
            if(jh[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            if(fire[nx][ny] != -1 && fire[nx][ny] <= jh[cur.X][cur.Y]+1) continue;
            jh[nx][ny] = jh[cur.X][cur.Y]+1;
            Q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}