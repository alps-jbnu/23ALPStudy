#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

int v, e, k;
vector<pair<int,int>> adj[1005]; // {비용, 정점 번호}
bool chk[1005]; // chk[i] : i번째 정점이 최소 신장 트리에 속해있는가?
vector<int> power; //발전소 번호 저장

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> k;
    for(int i=0; i<k; i++) { //발전소 번호 입력
        int a;
        cin >> a;
        power.push_back(a);
    }
    for(int i = 0; i < e; i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }

    int ans = 0;
    // tuple<int,int,int> : {비용, 정점 1, 정점 2}
    priority_queue< tuple<int,int,int>,
                    vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>> > pq;
    for(int i=0; i<k; i++) {
      chk[power[i]]=1;
      for(auto nxt: adj[power[i]]){
        pq.push({nxt.X, power[i], nxt.Y});
      }
    }

    while(!pq.empty()){
        int cost, a, b;
        tie(cost, a, b) = pq.top(); pq.pop();
        if(chk[b]) continue;
        ans += cost;
        chk[b] = 1;
        for(auto nxt : adj[b]){
            if(!chk[nxt.Y]) {
                pq.push({nxt.X, b, nxt.Y});
            }
        }
    }
    cout << ans;
}