#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[101][101];
bool vis[101][101];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue <pair<int, int>> q;
vector <int> v;
int s = 0;

void BFS(int y, int x, int t) {
    vis[y][x] = true;
    q.push(make_pair(y, x));
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
                continue;
            }
            if (map[ny][nx] > t && vis[ny][nx] == false) {
                vis[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    int x, f = 0, p = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            p = max(p, map[i][j]);
        }
    }
    int cnt = 0;
    for (int k = 0; k <= p; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] > k && vis[i][j] == false) {//방문하려는 곳이 1이고 아직 방문하지 않았다면방문
                    BFS(i, j, k);
                    s++;
                }
            }
        }
        v.push_back(s);
        s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = 0;
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << "\n";

}
