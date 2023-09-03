#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[301][301]; 
int t, l, x1, y1, x2, y2;
int dx[8]={2, 1, -1, -2, -2, -1, 1, 2};
int dy[8]={-1, -2, -2, -1, 1, 2, 2, 1};
queue<pair<int, int>> Q;

int bfs(int, int, int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>t;
    while(t--){
        cin>>l;
        for(int i=0; i<l; i++)
            fill(board[i], board[i]+l, -1);
        cin>>x1>>y1; //현재 위치
        Q.push({x1, y1});
        board[x1][y1]=0;
        cin>>x2>>y2; //이동할 위치
        cout<<bfs(l, x2, y2)<<'\n';
    }
}

int bfs(int l, int x2, int y2){
    while(!Q.empty()){
        auto cur=Q.front();
        Q.pop();

        for(int i=0; i<8; i++){
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            if(nx<0||nx>=l||ny<0||ny>=l) continue;
            if(board[nx][ny]>=0) continue;
            board[nx][ny]=board[cur.X][cur.Y]+1;
            Q.push({nx, ny});
        }
    }
    return board[x2][y2];
}