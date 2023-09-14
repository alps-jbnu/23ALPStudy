#define MAX 1001
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
string board[MAX];
bool vis[MAX][MAX];
// bool perimeter_vis[1002][1002];

int perimeter_count(pair<int, int> cur) {
    int ret{};
    for(int i{}; i<4; i++) {
        auto nxt{cur};
        nxt.first += dx[i];
        nxt.second += dy[i];

        if(nxt.first<0 || nxt.first>=N || nxt.second<0 || nxt.second>=N || board[nxt.first][nxt.second] == '.') {
            ret++;
        }
    }
    return ret;
}

pair<int, int> bfs(pair<int, int> st) {
    int area{}, perimeter{};
    queue<pair<int, int>> q;
    vis[st.first][st.second] = true;
    area++;
    perimeter += perimeter_count(st);
    q.push(st);
    while(!q.empty()) {
        auto cur{q.front()};
        q.pop();
        for(int i{}; i<4; i++) {
            auto nxt{cur};
            nxt.first += dx[i];
            nxt.second += dy[i];

            if(nxt.first<0 || nxt.first>=N || nxt.second<0 || nxt.second>=N) continue;
            if(vis[nxt.first][nxt.second]) continue;
            if(board[nxt.first][nxt.second] == '.') continue;

            vis[nxt.first][nxt.second] = true;
            area++;
            perimeter += perimeter_count(nxt);
            q.push(nxt);
        }
    }
    return {area, perimeter};
}

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if(a.first==b.first) return a.second>b.second;
        else return a.first<b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    for(int i{}; i<N; i++) {
        cin>>board[i];
    }
    for(int i{}; i<N; i++) {
        for(int j{}; j<N; j++) {
            if(vis[i][j]) continue;
            if(board[i][j]=='.') continue;
            ans.push(bfs({i,j}));
        }
    }
    cout<<ans.top().first<<" "<<ans.top().second;

    return 0;
}