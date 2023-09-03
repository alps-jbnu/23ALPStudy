#include<iostream>
#include<vector>
#include<queue>
const int MX=1004;
using namespace std;

int N,M;
vector<pair<int, int>> w_al[MX];
int vis[MX];
void bfs(int s,const int& t){
    queue<pair<int,int>> q; q.emplace(s,0); //★★★mark distance from `s`
    vis[s]=1;
    while(!q.empty()){
        auto [cur,dist]=q.front();  q.pop();//dequeue
        if(cur==t){
            cout<<dist<<'\n';
            return;
        }
        for(auto [nxt,nxtDist]:w_al[cur]){
            if(vis[nxt])continue;
            vis[nxt]=1;
            q.emplace(nxt,dist+nxtDist);    //enqueue
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N-1;i++){
        int v1,v2,w;    cin>>v1>>v2>>w;
        w_al[v1].emplace_back(v2,w);    //push_back
        w_al[v2].emplace_back(v1,w);
    }
    while(M--){
        int s,t;    cin>>s>>t;
        fill(vis+1,vis+N+1,0);
        bfs(s,t);
    }
}
