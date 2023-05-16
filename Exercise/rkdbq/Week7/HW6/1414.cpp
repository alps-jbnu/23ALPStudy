#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int N, total;
vector<pair<int, int>> adj[51];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
set<int> s;

int prim() {
    pq.push({0, 0});
    int cnt{};
    while(!pq.empty()) {
        if(s.size() == N) break;
        auto cur{pq.top()};
        pq.pop();
        if(s.find(cur.first) != s.end()) continue;
        s.insert(cur.first);
        cnt += cur.second;
        for(int i{}; i<adj[cur.first].size(); i++) {
            pq.push({adj[cur.first][i].first, adj[cur.first][i].second});
        }
    }
    if(s.size() != N) cnt = -1;
    else cnt = total - cnt;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    for(int i{}; i<N; i++) {
        for(int j{}; j<N; j++) {
            char len;
            cin>>len;
            if(len == '0') continue;
            if(len <= 'Z') {
                adj[i].push_back({j, len - 'A' + 27});
                adj[j].push_back({i, len - 'A' + 27});
                total += (len - 'A' + 27);
            }
            else {
                adj[i].push_back({j, len - 'a' + 1});
                adj[j].push_back({i, len - 'a' + 1});
                total += (len - 'a' + 1);
            }
        }
    }

    cout<<prim();

    return 0;
}