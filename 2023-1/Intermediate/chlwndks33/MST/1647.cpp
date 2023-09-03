//baekjoon - 1647번 도시 분할 계획

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
vector<pair<int,int>> adj[100005];
bool chk[100005];
int v, e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    int mc = 0;
    long long ans = 0;

    cin >> v >> e;
    while(e--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost,b});
        adj[b].push_back({cost,a});
    }
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>> > pq;
    chk[1] = 1;
    for(auto nxt : adj[1])
        pq.push({nxt.X, 1,nxt.Y});
    while(cnt < v-1) {
        int cost, a, b;
        tie(cost, a,b) = pq.top();
        pq.pop();
        if(chk[b]) continue; // 이미 mst에 들어가있는 경우
        ans += cost;
        mc = max(cost,mc); //두 마을을 잇는 간선의 최대비용 mc
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]) {
            if(!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
        }
    }
    cout << ans-mc;
}