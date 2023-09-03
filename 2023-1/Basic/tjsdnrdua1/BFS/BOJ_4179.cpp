#include<iostream>
#include<utility>
#include<deque>
using namespace std;
#define X first
#define Y second
string M[1002];     //Maze
int Jd[1002][1002]; int Fd[1002][1002];             //distance of J & Fire: 0 0 ... 0
deque<pair<int,int>> JQ; deque<pair<int,int>> FQ;   //큐처럼 사용
int dx[]={-1,0,1,0}; int dy[]={0,1,0,-1};   //↑ → ↓ ←
int r,c;        //row&column
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>r>>c;
    for(int i=0;i<r;i++) cin>>M[i];
    for(int j=0;j<r;j++){
        for(int k=0;k<c;k++){
            if(M[j][k]=='F')
                FQ.push_back({j, k});
            else if(M[j][k]=='J') {
                JQ.push_back({j, k});
                Fd[j][k] = -1;
            }
            else if(M[j][k]=='.'){
                Jd[j][k]=-1; Fd[j][k]=-1;
            }
        }
    }
    while(!FQ.empty()){
        auto cur=FQ.front(); FQ.pop_front();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir]; int ny=cur.Y+dy[dir];
            if(nx<0||nx>=r||ny<0||ny>=c) continue;  //OutOfBounds
            if(Fd[nx][ny]>=0) continue;
            Fd[nx][ny]=Fd[cur.X][cur.Y]+1;
            FQ.push_back({nx,ny});
        }
    }
    while(!JQ.empty()){
        auto cur=JQ.front(); JQ.pop_front();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir]; int ny=cur.Y+dy[dir];
            if(nx<0||nx>=r||ny<0||ny>=c) continue;      //OutOfBounds
            if(Jd[nx][ny]>=0) continue;
            //can't go to fire //int(0xffffffff)==-1; -> w.o. Fd[nx][ny]!=-1; error
            if(Jd[cur.X][cur.Y]+1>=Fd[nx][ny]&&Fd[nx][ny]!=-1) continue;
            Jd[nx][ny]=Jd[cur.X][cur.Y]+1;
            JQ.push_back({nx,ny});
        }
    }
    int res=r+c-1;
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if((0<i&&i<r-1)&&(0<j&&j<c-1)) continue;    //check ONLY boundary of the Maze
            if(M[i][j]=='#'||M[i][j]=='F') continue;    //except fire source, wall
            if(Jd[i][j]==-1) continue;                  //fail to escape
            cnt++;
            res=min(res,Jd[i][j]);
        }
    }
    if(cnt==0){cout<<"IMPOSSIBLE"; return 0;}
    else cout<<res+1;
}