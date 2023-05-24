#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> adj[32001];
vector<int> result;
int inComing[32001];
priority_queue<int, vector<int>, greater<int>> pq;


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
    for(int i=1; i<=n; i++) {
        if(inComing[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        result.push_back(cur);
        for(auto nxt: adj[cur]) {
            inComing[nxt]--;
            if(inComing[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
    for(auto e: result) {
        cout << e << " ";
    }

}