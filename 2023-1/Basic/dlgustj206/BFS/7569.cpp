#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int box[102][102][102];
int day[102][102][102];
int m, n, h; //가로(열), 세로(행), 높이(면)
int dx[6]={0, 0, 1, -1, 0, 0};
int dy[6]={1, -1, 0, 0, 0, 0};
int dz[6]={0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> Q;

void bfs(int, int, int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>m>>n>>h;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>box[i][j][k];
                if(box[i][j][k]==1) Q.push({j, k, i});
                if(box[i][j][k]==0) day[i][j][k]=-1;
            }
        }
    }

    bfs(n, m, h);
    int max_day=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(day[i][j][k]==-1){
                    cout<<-1<<"\n";
                    return 0;
                }
                max_day=max(max_day, day[i][j][k]);
            }
        }
    }
    cout<<max_day<<"\n";
}

void bfs(int n, int m, int h){
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();
        int curX, curY, curZ;
        tie(curX, curY, curZ)=cur;
        
        for(int dir=0; dir<6; dir++){
            int nx=curX+dx[dir];
            int ny=curY+dy[dir];
            int nz=curZ+dz[dir];
            if(nx<0||nx>=n||ny<0||ny>=m||nz<0||nz>=h) continue;
            if(day[nz][nx][ny]>=0) continue;
            day[nz][nx][ny]=day[curZ][curX][curY]+1;
            Q.push({nx, ny, nz});
        }
    }
}