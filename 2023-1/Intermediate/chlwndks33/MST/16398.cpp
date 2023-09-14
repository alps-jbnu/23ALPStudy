//baekjoon - 16398번 행성 연결 - 프림알고리즘
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
vector<pair<int,int>> adj[1005];
bool chk[1005];
int v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    long long ans = 0;

    cin >> v;
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            int cost;
            cin >> cost;
            if(i==j) continue;
            adj[i].push_back({cost,j});
        }
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
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]) {
            if(!chk[nxt.Y])
                pq.push({nxt.X, b, nxt.Y});
        }
    }
    cout << ans;
}