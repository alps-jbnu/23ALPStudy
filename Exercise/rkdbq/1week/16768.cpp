#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

string grid[101];
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, K;

queue<pair<int, int>> Q;
vector<pair<int, int>> V;

bool isDisappeared = true;
void disappear() {
    for(auto it=V.begin(); it != V.end(); it++) {
        auto cur = *it;
        grid[cur.first][cur.second] = '0';
    }
}

void bfs(pair<int, int> pos, char color) {
    if(color == '0') return;

    V.clear();
    Q.push(pos);
    visited[pos.first][pos.second] = true;
    V.push_back(pos);

    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for(int i{}; i<4; i++) {
            auto nxt = cur;
            nxt.first += dx[i];
            nxt.second += dy[i];

            if(nxt.first < 0 || nxt.first >=N) continue;
            if(nxt.second < 0 || nxt.second >= 10) continue;
            if(visited[nxt.first][nxt.second]) continue;
            if(grid[nxt.first][nxt.second] != color) continue;
            Q.push(nxt);
            visited[nxt.first][nxt.second] = true;
            V.push_back(nxt);
        }
    }

    if(V.size() >= K) {
        disappear();
        isDisappeared = true;
        V.clear();
    }
}

void init() {
    for(int i{}; i<101; i++) {
        for(int j{}; j<101; j++) visited[i][j] = false;
    }
    V.clear();
    isDisappeared = false;
}

stack<char> S;
void gravity() {
    for(int i{}; i<10; i++) {
        for(int j{}; j<N; j++) {
            S.push(grid[j][i]);
            grid[j][i] = '0';
        }
        int cur = N-1;
        while(!S.empty()) {
            if(S.top() != '0') {
                grid[cur][i] = S.top();
                cur--;
            }
            S.pop();
        }
    }
}

void curGrid() {
    for(int i{}; i<N; i++) {
        for(int j{}; j<10; j++) {
            cout<<grid[i][j];
        }
        cout<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>K;
    for(int i{}; i<N; i++) {
        cin>>grid[i];
    }

    while(isDisappeared == true) {
        init();
        for(int i{}; i<N; i++) {
            for(int j{}; j<10; j++) {
                bfs({i, j}, grid[i][j]);
            }
        }
        gravity();
    }

    curGrid();

    return 0;
}