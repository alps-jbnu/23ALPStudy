#define INT_MAX 2147483647
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n, min_dis{INT_MAX};
string from_map[5], moved_map[5];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

vector<pair<int, int>> st;

int dis(vector<pair<int, int>> from, vector<pair<int, int>> to) {
    int ret{};
    for(int i{}; i<n; i++) {
        ret += (abs(from[i].first-to[i].first) + abs(from[i].second-to[i].second));
    }
    return ret;
}

int bfs(pair<int, int> st, string map[5]) {
    int cnt = 0;
    bool vis[5][5];
    for(int i{}; i<5; i++) for(int j{}; j<5; j++) vis[i][j] = false;
    queue<pair<int, int>> q;
    vis[st.first][st.second] = true;
    cnt++;
    q.push(st);
    while(!q.empty()) {
        auto cur{q.front()};
        q.pop();
        for(int i{}; i<4; i++) {
            auto nxt{cur};
            nxt.first += dx[i];
            nxt.second += dy[i];

            if(nxt.first<0 || nxt.first>=5 || nxt.second<0 || nxt.second>=5) continue;
            if(map[nxt.first][nxt.second] == '.') continue;
            if(vis[nxt.first][nxt.second]) continue;

            vis[nxt.first][nxt.second] = true;
            cnt++;
            q.push(nxt);
        }
    }
    return cnt;
}

void find_moved_map(vector<pair<int, int>> moved) {
    if(moved.size() == n) {
        if(bfs(moved[0], moved_map) == n) {
            min_dis = min(min_dis, dis(moved, st));
        }
        return;
    }
    for(int i{}; i<5; i++) {
        for(int j{}; j<5; j++) {
            if(moved_map[i][j] == '*') continue;
            moved_map[i][j] = '*';
            moved.push_back({i, j});
            find_moved_map(moved);
            moved_map[i][j] = '.';
            moved.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i{}; i<5; i++) {
        for(int j{}; j<5; j++) {
            cin>>from_map[i][j];
            if(from_map[i][j] == '*') {
                n++;
                st.push_back({i, j});
            }
        }
    }
    for(int i{}; i<5; i++) {
        for(int j{}; j<5; j++) {
            moved_map[i][j] = '.';
        }
    }
    vector<pair<int, int>> v;
    find_moved_map(v);
    cout<<min_dis;

    return 0;
}