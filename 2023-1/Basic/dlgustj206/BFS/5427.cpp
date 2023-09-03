#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

string build[1001];
int fire[1001][1001]; //불의 이동 시간
int man[1001][1001]; //상근이의 이동 시간
int t, n, m;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
queue<pair<int, int>> Q1; //불
queue<pair<int, int>> Q2; //상근이

int bfs(int, int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    while(t--){
        cin>>m>>n;
        while(!Q1.empty()) Q1.pop();
        while(!Q2.empty()) Q2.pop();
        for(int i=0; i<n; i++){
            fill(fire[i], fire[i]+m, -1);
            fill(man[i], man[i]+m, -1);
        }

        for(int i=0; i<n; i++)
            cin>>build[i];
            
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(build[i][j]=='*'){
                    Q1.push({i, j});
                    fire[i][j]=0;
                }
                if(build[i][j]=='@'){
                    Q2.push({i, j});
                    man[i][j]=0;
                }
            }
        }
        bfs(n, m);  
    }
}

int bfs(int n, int m){
    bool escape=false;

    //불에 대한 bfs
    while(!Q1.empty()){
        auto cur1=Q1.front();
        Q1.pop();

        for(int i=0; i<4; i++){
            int nx=cur1.X+dx[i];
            int ny=cur1.Y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(build[nx][ny]=='#'||fire[nx][ny]>=0) continue;
            fire[nx][ny]=fire[cur1.X][cur1.Y]+1;
            Q1.push({nx, ny});
        }
    }

    //상근이에 대한 bfs
    while(!Q2.empty()&&!escape){
        auto cur2=Q2.front();
        Q2.pop();

        for(int i=0; i<4; i++){
            int nx=cur2.X+dx[i];
            int ny=cur2.Y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m){
                cout<<man[cur2.X][cur2.Y]+1<<'\n';
                escape=true;
                break;
            }
            if(build[nx][ny]=='#'||man[nx][ny]>=0) continue;
            if(fire[nx][ny]!=-1&&fire[nx][ny]<=man[cur2.X][cur2.Y]+1) continue;
            man[nx][ny]=man[cur2.X][cur2.Y]+1;
            Q2.push({nx, ny});
        }
    }
    if(!escape)
        cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}