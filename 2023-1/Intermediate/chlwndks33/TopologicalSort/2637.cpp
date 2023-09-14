#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int,int>> adj[105];
int inComing[105];
int mid[105]; // 기본부품인지 아닌지 확인하는 배열
int d[105];
queue<int> q;
vector<int> basic;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--) {
        int a, b, num;
        cin >> a >> b >> num;
        adj[a].push_back({b,num});
        inComing[b]++;
        mid[a] = 1;
    }
    q.push(n);
    d[n] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]) {
            d[nxt.first] += nxt.second * d[cur];
            inComing[nxt.first]--;
            if(inComing[nxt.first] == 0){
                q.push(nxt.first);
            }
        }
    }                                          

    for(int i=1; i<=n; i++) {
        if(!mid[i]) {
            cout << i << " " << d[i] << '\n';
        }
    }
}