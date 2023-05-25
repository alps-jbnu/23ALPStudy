#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,u,v;
int ans,cnt;
bool vis[501];
vector<int> g[501];
bool dfs(int x,int px){
    vis[x] = true;
    for(int i =0; i<g[x].size(); i++){//g[x].size의 경우는 현재 연결된 노드의 수임.
        if(g[x][i]==px)continue;//이전 노드와 연결된 노드의 경우 스킵.(역방향 엣지를 처리함. 역방향 엣지의 경우는 사이클을 이루지 않으므로 탐색 필요 X)
        if(vis[g[x][i]])return false;//이미 방문한 노드 처리
        if(dfs(g[x][i],x)==false) return false;//사이클이 존재하지 않은 경우 처리
    }
    return true;
}
int main(void){
    while(true){
        cin >> n>>m;
        if(n==0&&m==0)break;
        cnt++;
        ans = 0;
        for(int i =1; i<=500; i++){
            g[i].clear();
            vis[i] = false;
        }
        for(int i =0; i<m; i++){
            cin >> u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i = 1; i<=n; i++){
            if(!vis[i])
                if(dfs(i,0)) ans++;
        }
        cout << "Case " << cnt << ": ";
        if (ans > 1)
            cout << "A forest of " << ans << " trees." << '\n';
        else if (ans == 1)
            cout << "There is one tree." << '\n';
        else if (ans == 0)
            cout << "No trees." << '\n';
    }
}
