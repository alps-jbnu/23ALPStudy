#include <iostream>
#include <utility>
#include<cstring>
#include <queue>
#include<string>
#include<algorithm>
#define Z first
#define X second.first
#define Y second.second
using namespace std;
int n,m,h;
int map[101][101][101];
int dist[101][101][101];
bool via[101][101][101];
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {-1,1,0,0,0,0};
int dz[6] = {0,0,0,0,-1,1};
int ans = 0;
queue<pair<int,pair<int,int>>> q;
int main(void)
{
    cin >>m>>n>>h;
    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                cin >> map[i][j][k];
                if(map[i][j][k]==1)
                    q.push({i,{j,k}});
                if(map[i][j][k]==0)
                    dist[i][j][k]=-1;
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i = 0; i<6; i++){
            int nz = cur.Z+dz[i];
            int nx = cur.X+ dx[i];
            int ny = cur.Y+ dy[i];
            
            if(nx<0||ny<0||nz<0||nx>=n||ny>=m||nz>=h) continue;
            if(dist[nz][nx][ny]>=0)continue;
            dist[nz][nx][ny] = dist[cur.Z][cur.X][cur.Y]+1;
            q.push({nz,{nx,ny}});
            
        }
    }
   
    for(int i = 0; i<h; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++){
                if(dist[i][j][k]==-1){
                    cout << -1;
                    return 0;
                }
                ans = max(dist[i][j][k],ans);
                
            }
        }
    }
    cout << ans;


}
        
    

