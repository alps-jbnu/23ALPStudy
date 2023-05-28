#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int,int>> adj[1001];
int main(void){
    int n,m,u,v,d;
    cin >> n>>m;
    for(int i = 0; i<n-1; i++){
        cin >>u>>v>>d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});//양방향으로 간선 추가.
        
    }
    while(m--){
        cin >>u>>v;
        queue<pair<int,int>> q;//q는 BFS를 위한 큐로, {노드 번호, 누적 거리} 쌍을 저장
        vector<bool> vis(n+1);//메모리 효율성과 성능 향상을 위한 선택
        q.push({u,0});
        while (!q.empty()) {
            auto [cur, dist] = q.front();
            q.pop();
            if (cur == v) {//목표노드와 같은지 비교함. 맞을 경우 가중치(거리)를 출력.
                cout << dist << '\n';
                break;
            };
            
            for(auto[nxt,nxtDist]: adj[cur]){
                if(vis[nxt])continue;
                vis[nxt] = true;
                q.push({nxt, dist+nxtDist});//방문하지 않은 노드인 경우, 방문 표시를 하고 큐에 {인접 노드, 누적 거리 + 가중치}를 삽입->누적 거리에 현재 노드와 인접 간선 가중치 더함.
            }
        }
    }
}

