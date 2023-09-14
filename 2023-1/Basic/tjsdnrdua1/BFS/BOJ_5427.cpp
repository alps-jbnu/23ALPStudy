#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
const int MX=1003;
//`fDist,dist,board` inside while(t--){..} -> segmentation_fault 0xc00000fd
int fDist[MX][MX],dist[MX][MX];
string board[MX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int w,h;
        queue<pair<int,int>> Q;
        queue<pair<int,int>> fQ;
        cin>>w>>h;
        bool isPoss=false;
        for(int i=0;i<h;i++){
            cin>>board[i];
            for(int j=0;j<w;j++){
                if(board[i][j]=='@') {
                    Q.push({i,j});
                    fDist[i][j]=-1;
                }
                else if(board[i][j]=='*')
                    fQ.push({i,j});
                else if(board[i][j]=='.'){
                    fDist[i][j]=-1;
                    dist[i][j]=-1;
                }
            }
        }
        while(!fQ.empty()){
            auto cur=fQ.front(); fQ.pop();
            for(int d=0;d<4;d++){
                int nx=cur.X+dx[d]; int ny=cur.Y+dy[d];
                if(nx<0||nx>=h||ny<0||ny>=w) continue;
                if(fDist[nx][ny]!=-1) continue;
                fDist[nx][ny]=fDist[cur.X][cur.Y]+1;
                fQ.push({nx,ny});
            }
        }
        while(!Q.empty()){
            auto cur=Q.front(); Q.pop();
            for(int d=0;d<4;d++){
                int nx=cur.X+dx[d]; int ny=cur.Y+dy[d];
                if(nx<0||nx>=h||ny<0||ny>=w) {
                    cout<<dist[cur.X][cur.Y]+1<<'\n';
                    isPoss=true;
                    break;
                }
                if(dist[nx][ny]!=-1) continue;      //.(a room)
                if(dist[cur.X][cur.Y]+1>=fDist[nx][ny]&&fDist[nx][ny]!=-1) continue;
                //if there's no *(fire) error -> if(...&&fDist[nx][ny]!=-1)
                dist[nx][ny]=dist[cur.X][cur.Y]+1;
                Q.push({nx,ny});
            }
            if(isPoss) break;
        }
        if(!isPoss) cout<<"IMPOSSIBLE\n";
        //segmentation_fault -> init_ fDist[][],dist[][],board[][] as 0
        for(int a=0;a<h;a++){
            for(int b=0;b<w;b++){
                fDist[a][b]=0;
                dist[a][b]=0;
                board[a][b]=0;
            }
        }
    }
}