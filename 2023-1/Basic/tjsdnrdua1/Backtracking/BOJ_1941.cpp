#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
string grp[5];
bool mask[25];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(auto& e:grp)
        cin>>e;
    //25명 중 7명 뽑는 모든 조합 체크 by next_perm_
    fill(mask+7,mask+25,1);
    do{
        queue<pair<int,int>> q;
        int cntS=0,cntAdjS=0;
        bool sevenS[5][5]={},vis[5][5]={};
        for(int i=0;i<25;i++){//앞의 7명만 칠공주라고 가정
            if(!mask[i]){
                int x=i/5,y=i%5;
                sevenS[x][y]=1;
                if(q.empty()){//처음 만나는 것만 enqueue
                    q.push({x,y});
                    vis[x][y]=1;
                }
            }
        }
        while(!q.empty()){//`S`칸 기준 상하좌우 bfs
            int x,y; tie(x,y)=q.front(); q.pop();//dequeue
            cntAdjS++;
            cntS+=((grp[x][y]=='S')?1:0);
            for(int d=0;d<4;d++){
                int nx=x+dx[d],ny=y+dy[d];
                if(nx<0||nx>=5||ny<0||ny>=5)continue;
                if(vis[nx][ny]||!sevenS[nx][ny])continue;
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
        ans+=((cntAdjS>=7&&cntS>=4)?1:0);
    }while(next_permutation(mask,mask+25));
    cout<<ans;
}