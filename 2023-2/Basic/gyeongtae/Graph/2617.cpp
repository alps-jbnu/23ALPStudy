#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, s = 0,h = 0;
bool vis[100], vis1[100];
vector <int> v1[100];
vector <int> v2[100];

void bfs(int t) {
    vis[t] = true;
    queue <int> q;
    q.push(t);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0;i < v1[cur].size();i++) {
            int next = v1[cur][i];
            if (!vis[next]) {
                vis[next] = true;
                q.push(next);
                s++;
            }
        }
    }
}

void bfs1(int t) {
    vis1[t] = true;
    queue <int> q;
    q.push(t);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0;i < v2[cur].size();i++) {
            int next = v2[cur][i];
            if (!vis1[next]) {
                q.push(next);
                vis1[next] = true;
                h++;
            }
        }
    }
}

void clear() {
    s = 0;
    h = 0;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        vis1[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        cin >> a >> b;
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    int k = 0;
    for (int i = 1;i <= n;i++) {
        clear();
        bfs(i);
        bfs1(i);
        //cout << i << "번째" << s << " " << h << "\n";
        if (s > (n - 1) / 2 || h > (n - 1) / 2) {
            //cout << (n - 1) / 2 << " " << i << "번째\n";
            k++;
        }
    }
    cout <<k;
}
