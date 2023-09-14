#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int map[626][626] = { 0, };
bool vis[626][626] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector <int> v;
queue<pair<int,int>> q;
int s = 1;

void bfs(int y, int x) {
    q.push(make_pair(y,x));
    vis[y][x] = true;

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }
            if (map[ny][nx] == 1&&vis[ny][nx]==0) {
                q.push(make_pair(ny, nx));
                vis[ny][nx] = true;
                s++;
            }
        }
    }
}


int main() {
    cin >> n;
    string q;
    for (int i = 0; i < n; i++) {
        cin >> q;
        for (int j = 0; j < n; j++) {
            map[i][j] = q[j] - '0';
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 1 && vis[i][j] == 0) {
                bfs(i, j);
                v.push_back(s);
                s = 1;
            }
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for (int i = 0;i < v.size();i++) {
        cout << v[i] << "\n";
    }
}
