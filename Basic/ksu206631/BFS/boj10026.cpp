#include <iostream>
#include <utility>
#include<cstring>
#include <queue>
#include<string>
#include<algorithm>

using namespace std;
int n,m;
int map[101][101];
bool vis[101][101];
int dist[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
queue<pair<int,int>> q;
void bfs(int i, int j){
    q.push({i,j});
    vis[i][j] = true;
    dist[i][j] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i =0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m){
                if(vis[nx][ny]==false){
                    if(map[nx][ny]==map[x][y]){
                        vis[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                    
                }
            }
            
            
                
        }
    }
    
}
int main(void){
    cin>>n;
    
    for(int i = 0; i<n; i++){
        string str;
        cin >>str;
        for(int j = 0; j<n;j++)
            map[i][j] = str[j];
    }
    int res = 0;
    int rgres  = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){//적록 생맹이 아닌 사람이 그림을 바라본 경우
            if(!vis[i][j]){
                bfs(i,j);
                res++;
            }
        }
    }
    
    memset(vis,false,sizeof(vis));
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){//적록 색맹은 녹색을 빨간색으로 인식.?
            if(map[i][j]=='G') map[i][j] = 'R';
        }
        
    }
   
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(!vis[i][j]){
                bfs(i,j);//적록 색맹이 볼 때
                rgres++;
                
            }
            
        }
    }
    cout << res<< " "<<rgres;
}
