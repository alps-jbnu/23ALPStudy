#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

char rgb[101][101];
int vis[101][101];
int n;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

int area();
void bfs(int, int);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>rgb[i][j];
        }
    }

    //적록색약이 아닌 사람
    int num1=area();

    for(int i=0; i<n; i++)
        fill(vis[i], vis[i]+n, 0);
        
    //적록색약인 사람
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(rgb[i][j]=='G')
                rgb[i][j]='R';
        }
    }
    int num2=area();

    cout<<num1<<' '<<num2;
}

void bfs(int i, int j){
    queue<pair<int, int>> Q;
    Q.push({i, j});
    vis[i][j]=1;
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(vis[nx][ny]==1||rgb[i][j]!=rgb[nx][ny]) continue;
            vis[nx][ny]=1;
            Q.push({nx, ny});
        }
    }
}

int area(){
    int num=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j]==0){
                num++;
                bfs(i, j);
            }
        }
    }
    return num;
}