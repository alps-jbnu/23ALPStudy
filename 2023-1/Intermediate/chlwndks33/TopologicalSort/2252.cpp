#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> adj[32001];
int inComing[32001]; // incoming edge를 담는 배열
vector<int> result; // 최종 위상정렬
queue<int> que;  // incoming == 0 인 정점을 담는 que

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        inComing[b]++;
    }
    for(int i=1; i<=n; i++) {  // incomming edge가 0인 정점 큐에 push
        if(inComing[i] == 0) {
            que.push(i);
        }
    }
    while(!que.empty()) {
        int cur = que.front();
        result.push_back(cur);
        for(auto nxt : adj[cur]) {
            inComing[nxt]--;
            if(inComing[nxt] == 0) {
                que.push(nxt);
            }
        }
        que.pop();
    }
    for(auto e : result) {
        cout << e << " ";
    }


}