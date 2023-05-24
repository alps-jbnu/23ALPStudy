#define INT_MAX 2147483647
#define MAX 101
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int T, N, M, friends;
int min_dist[MAX][MAX]; // i번 친구가 j번 노드까지 도달하는 최단 거리
vector<pair<int, int>> adj[MAX];

void init() {
    memset(min_dist, 0, sizeof(min_dist));
    for(int i{}; i<MAX; i++) adj[i].clear();
}

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second>b.second;
    }
};

void dijkstra(pair<int, int> st, int friend_num) {
    bool vis[MAX];
    memset(vis, false, sizeof(vis));

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(st);
    while(!pq.empty()) {
        auto cur{pq.top()};
        pq.pop();
        if(vis[cur.first]) continue;
        vis[cur.first] = true;
        min_dist[friend_num][cur.first] = cur.second;
        for(int i{}; i<adj[cur.first].size(); i++) {
            auto nxt{adj[cur.first][i]};
            pq.push({nxt.first, cur.second + nxt.second});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>T;
    for(int t{}; t<T; t++) {
        init();
        cin>>N>>M;
        for(int i{}; i<M; i++) {
            int a, b, c;
            cin>>a>>b>>c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        cin>>friends;
        for(int i{}; i<friends; i++) {
            int pos;
            cin>>pos;
            dijkstra({pos, 0}, i);
        }

        int ans_dist{INT_MAX}, ans_node;
        for(int i{N}; i>0; i--) {
            int total_min_dist{};
            for(int j{}; j<friends; j++) {
                total_min_dist += min_dist[j][i];
            }
            if(total_min_dist<=ans_dist) {
                ans_dist = total_min_dist;
                ans_node = i;
            } 
        }
        cout<<ans_node<<"\n";
    }
    
    return 0;
}