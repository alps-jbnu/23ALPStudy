#include <iostream>
#include <queue>
#include <utility>
#include<algorithm>
#include<string>
#define X second
#define Y first
using namespace std;

char board[1001][1001];
int dist[1001][1001];
int dist2[1001][1001];
bool vis[1001][1001];
int dx[4]={0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<pair<int, int> > q1;
queue<pair<int, int> > q2;
int main(void){
    int t;
    cin >> t;
   
    while(t--){
        bool flag = false;
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        int w,h;
        cin>>w>>h;
        for(int i =0; i<h; i++){
            fill(dist[i],dist[i]+w,-1);
            fill(dist2[i],dist2[i]+w,-1);
            
        }
        
        
        for(int i = 0; i<h; i++)
        {
            for(int j  = 0; j<w; j++)
            {
                cin >> board[i][j];
                if(board[i][j]=='*')
                {//불 bfs
                    dist[i][j] = 0;
                    q1.push({i,j});
                }
                else if(board[i][j]=='@')
                {//상근이 bfs
                    dist2[i][j] = 0;
                    q2.push({i,j});
                }
            }
        }
        while(!q1.empty()){
            auto cur = q1.front();
            q1.pop();
            for(int i = 0; i<4; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y+dy[i];
                if(nx<0||ny<0||nx>=w||ny>=h) continue;
                if(dist[ny][nx]>=0||board[ny][nx]=='#') continue;
                q1.push({ny,nx});
                dist[ny][nx]=dist[cur.Y][cur.X]+1;
                
            }
        }
        
        while(!q2.empty()&&(!flag)){
            auto cur = q2.front(); q2.pop();
            for(int i = 0; i<4; i++){
                int nx = cur.X + dx[i];
                int ny = cur.Y+dy[i];
                if(nx<0||ny<0||nx>=w||ny>=h) {
                    cout << dist2[cur.Y][cur.X]+1<<"\n";
                    flag = true;
                    break;
                }
                if(dist2[ny][nx]!=-1||board[ny][nx]=='#') continue;
                if(dist[ny][nx]!=-1&&dist[ny][nx]<=dist2[cur.Y][cur.X]+1) continue;
                
                dist2[ny][nx]=dist2[cur.Y][cur.X]+1;
                q2.push({ny,nx});
            }
            
        }
        if(!flag)
            cout << "IMPOSSIBLE"<<"\n";
        
        
    }
    
}
