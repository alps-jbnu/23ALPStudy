#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> adj[1001];
int inComing[1001];
vector<int> result;
queue<int> que;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--) {
        int a,b;
        cin >> a;
        vector<int> temp;
        while(a--) {
            cin >> b;
            temp.push_back(b);
        }
        for(int i=0; i<temp.size()-1; i++) {
            for(int j=i+1; j<temp.size(); j++) {
                adj[temp[i]].push_back(temp[j]);
                inComing[temp[j]]++;
            }
        }
    }
    for(int i=1; i<=n; i++) {
        if(inComing[i] == 0) {
            que.push(i);
        }
    }

    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        result.push_back(cur);
        for(auto nxt : adj[cur]) {
            inComing[nxt]--;
            if(inComing[nxt] == 0) {
                que.push(nxt);
            }
        }
    }
    if(result.size() != n) {
        cout << "0";
    }
    else {
        for(auto e: result) {
            cout << e << "\n";
        }
    }

}