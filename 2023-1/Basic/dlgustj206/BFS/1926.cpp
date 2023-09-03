#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[501][501];
bool vis[501][501];
int n, m; //n: 행, m: 열
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    //그림 정보 입력
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>board[i][j];

    int num=0; //그림의 개수
    int max_area=0; //넓이 최댓값
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]==0||vis[i][j]) continue;
            num++;
            queue<pair<int,int>> Q;
            vis[i][j]=1;
            Q.push({i, j});
            int area=0;
            while(!Q.empty()){
                area++;
                pair<int,int> cur=Q.front();
                Q.pop();
                for(int dir=0; dir<4; dir++){
                    int nx=cur.X+dx[dir];
                    int ny=cur.Y+dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(vis[nx][ny]||board[nx][ny]!=1) continue;
                    vis[nx][ny]=1;
                    Q.push({nx, ny});
                }
            }
            max_area=max(max_area, area);
        }
    }
    cout<<num<<"\n"<<max_area;
}