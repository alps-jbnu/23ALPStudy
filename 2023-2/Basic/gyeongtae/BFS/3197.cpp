#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
char map[1501][1501];
bool vis[1501][1501];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
int s = 0;
queue <pair<int, int>> q1,q2;
vector <pair<int, int>> v;

bool bfs_1() {
    queue <pair<int, int>> q;
    while (!q1.empty()) {
        int x = q1.front().first;
        int y = q1.front().second;
        q1.pop();
        if (x==v[1].first&&y==v[1].second) {
            return true;
        }
        for (int i = 0;i < 4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n||vis[nx][ny]) {
                continue;
            }
            if (map[nx][ny] == 'X') {
                q.push(make_pair(nx, ny));
            }
            else {
                q1.push(make_pair(nx ,ny));

            }
            vis[nx][ny] = true;
        }
    }
    q1 = q;
    return false;
}

void bfs() {
    int size = q2.size();
    while (size--) {
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        for (int i = 0;i < 4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n) {
                continue;
            }
            if (map[nx][ny] == 'X') {
                map[nx][ny] = '.';
                q2.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'L') {
                v.push_back(make_pair(i, j));
            }
            if (map[i][j] != 'X') {
                q2.push(make_pair(i, j));
            }
        }
    }
    q1.push(make_pair(v[0].first, v[0].second));
    vis[v[0].first][v[0].second] = true;
    while (1) {
        
        if (bfs_1()) {
            cout << a;
            break;
        }        
        bfs();
        a++;
    }
}
