#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

string board[101];
int dist[101][101];
int n, m;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

int bfs(int n, int m){
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    dist[0][0]=1;

    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();

        for(int i=0; i<4;i++){
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>0||board[nx][ny]!='1') continue;
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            Q.push({nx, ny});
        }
    }
    return dist[n-1][m-1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>board[i];

    cout<<bfs(n, m)<<'\n';
}