#include<iostream>
#include<queue>
#define x first
#define y second 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
using namespace std;
int main(){
    queue<pair<int,int> >Q; 
    int t;
    cin >> t;
    while(t--){
        int vis[51][51] = {}; //0으로 초기화
        int board[51][51] = {}; // 0으로 초기화
        int n,m,k;
        cin >> n >> m>>k;
        for(int i=0;i<k;i++){
            int a,b;
            cin >> a>> b;
            board[a][b] = 1; //입력받은곳에 양배추가 있으므로
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0 || vis[i][j] == 1) continue; // 양배추가 없거나 이미 방문한곳이면 for문의 다음조건으로 
                Q.push({i,j});
                vis[i][j] =1;
                ans++; // 개수를 증가시킨다
                while(!Q.empty()){ //주변에 양배추가 있는곳의 vis를 모두 1으로 만들어준다.
                    pair<int ,int> cur = Q.front();
                    Q.pop();
                    for(int dir =0;dir<4;dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(board[nx][ny]!=1 || vis[nx][ny] != 0) continue;
                        Q.push({nx,ny});
                        vis[nx][ny] =1;
                    }
                }
            }
        }
        cout<< ans<<"\n";
    }
    
}
