#include<iostream>
#include<queue>
#include<utility>
using namespace std;
#define X first
#define Y second
const int MX=303;
int dist[MX][MX];
int dx[]={-1,-1,1,1,-2,-2,2,2};
int dy[]={-2,2,-2,2,-1,1,-1,1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;
    int t; cin>>t;//tc
    while(t--){
        int s; cin>>s;//size
        for(int i=0;i<s;i++) fill(dist[i],dist[i]+s,-1);
        int ix,iy,fx,fy; cin>>ix>>iy>>fx>>fy;
        dist[ix][iy]=0; Q.push({ix,iy});
        while(!Q.empty()){
            auto cur=Q.front(); Q.pop();
//            if(cur.X==fx&&cur.Y==fy) break;   //tc2 output: 21    ans: 28
            for(int d=0;d<8;d++){
                int nx=cur.X+dx[d]; int ny=cur.Y+dy[d];
                if(nx<0||nx>=s||ny<0||ny>=s) continue;
                if(dist[nx][ny]!=-1) continue;
                if(nx==fx&&ny==fy) {
                    dist[nx][ny]=dist[cur.X][cur.Y]+1;
                    continue;
                }
                dist[nx][ny]=dist[cur.X][cur.Y]+1;
                Q.push({nx,ny});
            }
        }
        cout<<dist[fx][fy]<<'\n';
    }
}