#include <iostream>
#include <queue>
using namespace std;

int fri[501][501];
int vis[501];
int depth[501];
int n, m, a, b, cnt;

void bfs(int);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        fri[a][b]=fri[b][a]=1;
    }
    bfs(1);
    cout<<cnt;
}

void bfs(int x){
    queue<int> Q;
    Q.push(x);
    vis[x]=1;

    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();

        for(int i=1; i<=n; i++){
            if(vis[i]||fri[cur][i]==0) continue;
            Q.push(i);
            vis[i]=1;
            depth[i]=depth[cur]+1;
            if(depth[i]>2) return;
            cnt++;
        }
    }
}