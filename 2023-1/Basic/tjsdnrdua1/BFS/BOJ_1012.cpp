#include<iostream>
#include<queue>
#include<utility>
using namespace std;
const int MX=55;
int dx[]={1,0,-1,0}; int dy[]={0,1,0,-1};
#define X first
#define Y second
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t,m,n,k;    //TC,cols,rows,cabbages
    cin>>t;
    while(t--){
        int x,y,grpCnt=0;   //group of cabbages
        bool cab[MX][MX]={false,};
        bool vis[MX][MX]={false,};

        cin>>m>>n>>k;
        while(k--){cin>>x>>y;cab[y][x]=true;}   //yth Row,xth Col
        queue<pair<int,int>> Q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(!cab[i][j]||vis[i][j]) continue;
                Q.push({i,j});
                vis[i][j]=true;
                while (!Q.empty()) {
                    auto cur=Q.front(); Q.pop();
                    for(int d=0;d<4;d++){
                        int nx=cur.X+dx[d];int ny=cur.Y+dy[d];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(!cab[nx][ny]||vis[nx][ny]) continue;
                        vis[nx][ny]=true;
                        Q.push({nx,ny});
                    }
                }
                grpCnt++;
            }
        }
        cout<<grpCnt<<'\n';
    }
}