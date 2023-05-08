#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int dX[]={1,1,2,2,-1,-1,-2,-2};
int dY[]={2,-2,1,-1,2,-2,1,-1};
int coin,w,h;
int res=0x77777777;
bool barrier[202][202];
int dist[202][202][32];
bool OOB(int a,int b){
    return a<0||a>=h||b<0||b>=w;
}
queue<tuple<int,int,int>> q;

void bfs(){
    q.push({0,0,0});    dist[0][0][0]=0;    //starting point
    while(!q.empty()){
        int x,y,jumpcnt;    //jumpcnt: 말 찬스 쓴 횟수
        tie(x,y,jumpcnt)=q.front();
        q.pop();
        if(jumpcnt<coin){       //말 찬스 쓰는 bfs
            for(int d=0;d<8;d++){
                int nX=x+dX[d], nY=y+dY[d];
                if(OOB(nX,nY))continue;
                if(barrier[nX][nY])continue;
                //말 찬스 썼으므로 다음 칸의 jumpcnt <- jumpcnt+1 갱신 필요
                if(dist[nX][nY][jumpcnt+1]!=-1)continue;
                dist[nX][nY][jumpcnt+1]=dist[x][y][jumpcnt]+1;
                q.push({nX,nY,jumpcnt+1});
            }
        }
        for(int d=0;d<4;d++){   //말 찬스 안 쓰는 bfs
            int nx=x+dx[d], ny=y+dy[d];
            //범위 체크
            if(OOB(nx,ny))continue;
            //장애물 체크
            if(barrier[nx][ny])continue;
            //방문했었는지?
            if(dist[nx][ny][jumpcnt]!=-1)continue;
            //위 3개 조건 모두 통과: 다음 위치의 거리 갱신, 큐에 push
            dist[nx][ny][jumpcnt]=dist[x][y][jumpcnt]+1;
            q.push({nx,ny,jumpcnt});
        }
    }//★★★★★★i=coin 포함해야 함★★★★★★★★★★line32 생각
    for(int i=0;i<coin+1;i++)
        if(dist[h-1][w-1][i]!=-1)   //도착점(우하단) 갔다면,
            res=min(res,dist[h-1][w-1][i]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>coin>>w>>h;
    for(int i=0;i<202;i++)
        for(int j=0;j<202;j++)
            fill(dist[i][j],dist[i][j]+32,-1);

    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>barrier[i][j];
    bfs();
    //Debugging
//    for(int a=0;a<coin+1;a++) {
//        for (int i = 0; i < h; i++) {
//            for (int j = 0; j < w; j++) {
//                cout<<dist[i][j][a]<<" ";
//            }
//            cout<<'\n';
//        }
//        cout<<'\n';
//    }
    if(res!=0x77777777) cout<<res;
    else cout<<-1;
    return 0;
}