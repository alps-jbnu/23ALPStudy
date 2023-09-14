#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector <int> map[20001];
int vis[50001];
vector <int> v;
queue <int> q;

void bfs(int x) {
    q.push(x);
    vis[x] = 1;

    while (!q.empty()) {
        int r = q.front();
        q.pop();
        for (int i = 0; i < map[r].size(); i++) {
            int df = map[r][i];
            if (vis[df] == 0) {
                q.push(df);
                vis[df] = vis[r] + 1;
            }
        }
    }
    int maxVal = *max_element(vis + 1, vis + n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i] == maxVal) {
            v.push_back(i);
        }
    }
}


int main() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    bfs(1);

    cout << v[0] << " " << vis[v[0]]-1 << " " << v.size();
}
