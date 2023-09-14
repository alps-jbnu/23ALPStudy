#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[1001][1001] = { 0, };
bool vis[1001] = { 0, };
queue <int> q;

void bfs(int a) {
    q.push(a);
    vis[a] = true;
    cout << a << " ";
    while (!q.empty()) {
        a = q.front();
        q.pop();

        for (int i = 1;i <= n;i++) {
            if (!vis[i] && map[a][i] == 1) {
                q.push(i);
                vis[i] = true;
                cout << i << " ";
            }
        }
    }
}

void dfs(int a) {
    vis[a] = true;
    cout << a << " ";

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && map[a][i] == 1) {
            dfs(i);
        }
    }
}

int main() {
    int g, h, t;
    cin >> n >> m >> g;
    for (int i = 0; i < m; i++) {
        cin >> h >> t;
        map[h][t] = 1;
        map[t][h] = 1;
    }
    dfs(g);

    for (int i = 0; i <= n; i++) {
        vis[i] = 0;
    }
    cout << "\n";

    bfs(g);
}
