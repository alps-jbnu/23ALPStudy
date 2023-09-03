#include<iostream>
#include<deque>
#include<utility>
#define X first
#define Y second
using namespace std;
int TomBox[1002][1002];
//1: ripen(queue.push(pair<int,int> val)&date[][]=0), 0: unripe(date[][]=-1), -1: no space
int date[1002][1002];
int M,N;
int dx[]={-1,0,1,0}; int dy[]={0,1,0,-1};   //↑ → ↓ ←
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N;
    deque<pair<int,int>> Q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>TomBox[i][j];
            if(TomBox[i][j]==1)
                Q.push_back({i,j});
            if(TomBox[i][j]==0)
                date[i][j]=-1;
        }
    }
    while(!Q.empty()){
        auto cur=Q.front(); Q.pop_front();
        for(int dir=0;dir<4;dir++) {
            int nx=cur.X+dx[dir]; int ny=cur.Y+dy[dir];
            if(nx<0||nx>=N||ny<0||ny>=M) continue;  //OutOfBounds
            if(date[nx][ny]>=0) continue;          //※nowhere to move: ripen(0,1,...) or no space(0)
            date[nx][ny]=date[cur.X][cur.Y]+1;
            Q.push_back({nx,ny});
        }
    }
    int minDate=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(date[i][j]==-1){
                cout<<-1;
                return 0;
            }
            minDate=max(minDate,date[i][j]);
        }
    }
    cout<<minDate;
}