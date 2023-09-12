#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; 
int map[500][500] = { 0, };
bool vis[500][500] = { 0, };
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue <pair<int, int>> q;
vector <int> v;//카운트 세기
int s = 1;

void BFS(int y, int x) {
    vis[y][x] = true;
    q.push(make_pair(y, x));


    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if (map[ny][nx] == 1 && vis[ny][nx] == 0) {
                vis[ny][nx] = true;
                s++;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (map[i][j] == 1 && vis[i][j] == 0) {//방문하려는 곳이 1이고 아직 방문하지 않았다면방문
                BFS(i, j);
                v.push_back(s);
                cnt++;
                s = 1;
            }
        }
    }
    sort(v.begin(), v.end());

    cout << cnt << "\n";

    if (cnt == 0) {
        cout << 0 << "\n";
    }
    else {
        cout << v.back() << "\n";
    }

}
