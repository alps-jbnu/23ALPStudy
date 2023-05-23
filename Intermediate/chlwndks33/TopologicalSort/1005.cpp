#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) { 
        long long d[1001]={};
        int times[1001]={};
        int inComing[1001] = {};
        vector<int> adj[1001];
        queue<int> q;
        int n,k;
        cin >> n >> k;
        for(int i=1; i<=n; i++) {
            cin >> times[i];
        }
        while(k--) {
            int v, u;
            cin >> v >> u;
            adj[v].push_back(u);
            inComing[u]++;
        }
        int w;
        cin >> w;
        for(int i=1; i<=n; i++) {
            if(inComing[i] == 0) {
                q.push(i);
                d[i] = times[i];
            }
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nxt : adj[cur]) {
                inComing[nxt]--;
                d[nxt] = max(d[nxt], d[cur] + times[nxt]);
                if(inComing[nxt]== 0) {
                    q.push(nxt);
                }
            }
        }
        cout << d[w]<<'\n';

    }

    

    
}