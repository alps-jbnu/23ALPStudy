#define LLONG_MIN -9223372036854775807LL-1LL
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (pair<int, long long> a, pair<int, long long> b) {
        return a.second > b.second;
    }
};

int N, M, D, E;
vector<pair<int, int>> adj[100001];
long long h[100001], path[100001][2];
priority_queue<pair<int, long long>, vector<pair<int, long long>>, cmp> pq; //{next node, weight}

void dijkstra(pair<int, int> st, int is_korea) {
    pq.push(st);
    while(!pq.empty()) {
        auto cur{pq.top()};
        pq.pop();
        if(path[cur.first][is_korea] == -1) {
            path[cur.first][is_korea] = cur.second;
        }
        else continue;
        auto& nxt{adj[cur.first]};
        for(int i{}; i<nxt.size(); i++) {
            if(h[cur.first] >= h[nxt[i].first]) continue;
            pq.push({nxt[i].first, cur.second + nxt[i].second});
        }
    }
}

string max_value() {
    long long val{LLONG_MIN};
    for(int i{1}; i<N-1; i++) {
        if(path[i][0] == -1 || path[i][1] == -1) continue;
        val = max(val, h[i]*E - (path[i][0] + path[i][1])*D);
    }
    if(val == LLONG_MIN) return "Impossible";
    else return to_string(val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(path, -1, sizeof(path));

    cin>>N>>M>>D>>E;
    for(int i{}; i<N; i++) cin>>h[i];
    for(int i{}; i<M; i++) {
        int a, b, n;
        cin>>a>>b>>n;
        adj[a-1].push_back({b-1,n});
        adj[b-1].push_back({a-1,n});
    }

    dijkstra({0,0}, 0);
    dijkstra({N-1,0}, 1);
    cout<<max_value();

    return 0;
}