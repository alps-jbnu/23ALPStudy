#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int v,e;    //정점 개수, 엣지 개수
int v1,v2;  //입력으로 들어오는 두 정점
int ans;

vector<int> adj[505];    //adjacency list
int dist[505];

void bfs(int c){
    queue<int> q;
    q.push(c);
    dist[c]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
//        cout<<cur<<" ";
        for(auto nxt:adj[cur]){
            if(dist[nxt]!=-1) continue;
            q.push(nxt);
            dist[nxt]=dist[cur]+1;
            if(dist[nxt]<3)
                ans++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>v>>e;
    fill(dist+1,dist+v+1,-1);
    while(e--){
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    bfs(1);
    cout<<ans;
    //Debugging
//    cout<<'\n';
//    for(auto val: dist)
//        cout<<val<<" ";
    return 0;
}