#include<iostream>
#include<deque>
#include<tuple>
using namespace std;
deque<tuple<int,int,int>> Q;
int TomBox[102][102][102];
int date[102][102][102];
int M,N,H;
//↑, →, ↓, ←, fd, back
int dx[]={-1,0,1,0,0,0};
int dy[]={0,1,0,-1,0,0};
int dz[]={0,0,0,0,1,-1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>M>>N>>H;
    for(int i=0;i<H;i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> TomBox[j][k][i];
                get<0>(Q.front());
                if (TomBox[j][k][i] == 1)
                    Q.push_back({j, k, i});
                if (TomBox[j][k][i] == 0)
                    date[j][k][i] = -1;
            }
        }
    }
    while(!Q.empty()){
        auto cur=Q.front(); Q.pop_front();
        int curX,curY,curZ;
        tie(curX,curY,curZ)=cur;
        for(int dir=0;dir<6;dir++) {
            int nx=curX+dx[dir];
            int ny=curY+dy[dir];
            int nz=curZ+dz[dir];
            if(nx<0||nx>=N||ny<0||ny>=M||nz<0||nz>=H) continue;  //OutOfBounds
            if(date[nx][ny][nz]>=0) continue;                   //※nowhere to move: ripen(0,1,...) or no space(0)
            date[nx][ny][nz]=date[curX][curY][curZ]+1;
            Q.push_back({nx,ny,nz});
        }
    }
    int minDate=0;
    for(int i=0;i<H;i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (date[j][k][i] == -1) {
                    cout << -1;
                    return 0;
                }
                minDate = max(minDate, date[j][k][i]);
            }
        }
    }
    cout<<minDate;
}