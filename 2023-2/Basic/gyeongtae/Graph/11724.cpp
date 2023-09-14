#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[1001][1001] = { 0, };
bool vis[1001] = { 0, };
vector <int> v;
queue<int> q;
int s = 0;

void bfs(int x) {
    q.push(x);
    vis[x] = true;

    while (!q.empty()) {
        x = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (map[x][i] == 1&&vis[i]==0) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}


int main() {
    cin >> n >> m;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if(vis[i]==0) {
            bfs(i);
            s++;
        }
    }

    cout << s;
}
