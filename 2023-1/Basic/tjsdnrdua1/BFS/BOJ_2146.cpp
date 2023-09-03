#include<iostream>
#include<queue>
#include<utility>
#include<tuple>
#include<vector>
#define X first
#define Y second
int map[102][102];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,island_num=1;
int vis[102][102];
std::vector<std::pair<int,int>> land[10004];
using namespace std;

bool OOB(int a,int b){
    return a<0||a>=n||b<0 or b>=n;
}
void numberingIsland(){ //bfs 돌려서 섬 번호 매기기
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]||map[i][j]==0)continue;
            queue<pair<int,int>> q;
            q.push({i,j});  //queue.push
            vis[i][j]=true;         //mark as visited: 1
            while(!q.empty()){
                auto cur=q.front(); q.pop();
                map[cur.X][cur.Y]=island_num;       //numberingIsland
                land[island_num].push_back({cur.X,cur.Y});//vector.push_back(position of each island#)
                for(int d=0;d<4;d++){
                    int nx=cur.X+dx[d]; int ny=cur.Y+dy[d];
                    //check if it's out of range, visited, sea
                    if(OOB(nx,ny)||vis[nx][ny]||map[nx][ny]==0)continue;
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
            island_num++;
        }
    }
}
int MinBridgeLen(int idx){  //섬 번호(island_num) idx에 대해서 bfs
    queue<tuple<int,int,int>> Q;
    //vector에 저장된 `현재 섬 번호에 속한 칸(좌표)들`을 모두 큐에 push
    for(auto e:land[idx]){
        Q.push({e.X,e.Y,0});    //섬의 dist: 0
        vis[e.X][e.Y]=idx;
    }
    while(!Q.empty()){  //현재 섬에 해당하는 좌표들에 대해 동시에 bfs
        auto cur=Q.front(); Q.pop();
        int cx,cy,dist;
        tie(cx,cy,dist)=cur;
        for(int d=0;d<4;d++){
            int nx=cx+dx[d]; int ny=cy+dy[d];
            //OOB 제외
            if(OOB(nx,ny)||vis[nx][ny]==idx) continue;
            //이전에 방문한 경우(vis[][]값이 현재 섬의 island_num?) 제외
            if(vis[nx][ny]==idx) continue;
            //같은 섬인 경우 제외
            if(map[nx][ny]==idx) continue;
            //다른 섬 만난 경우: 현재 칸의 거리 반환
            if(map[nx][ny]!=0)
                return dist;
            //바다: 위 네 개에 모두 해당 안 되는 마지막 경우
            //1. 현재 수행 중인 섬의 idx를 vis에 갱신
            //2. 거리 1 추가한 상태로  큐에 push
            vis[nx][ny]=idx;
            Q.push({nx,ny,dist+1});
        }
    }
    return 99999999;    //문제 설정상 다른 섬 무조건 만나지만 형식상~
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>map[i][j];
    numberingIsland();
    int ans=20000;
    for(int i=1;i<5000;i++){
        if(land[i].empty())break;
        ans=min(ans,MinBridgeLen(i));
    }
    cout<<ans;
}