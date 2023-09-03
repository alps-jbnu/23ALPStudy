#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int dx[6] = { -1, 1, -2, 2, -1, 1 };
int dy[6] = { -2, -2, 0, 0, 2, 2 };

int dist[205][205];
bool vis[205][205];

int N;

queue<pair<int, int>> Q;

int main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    Q.push({ c1, r1 });
    dist[c1][r1] = 1;
    vis[c1][r1] = 1;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx > N || nx < 0 || ny > N || ny < 0) continue;
            if (vis[nx][ny] == true) continue;

            vis[nx][ny] = true;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({ nx, ny });

        }
    }

    /*   cout << '\n';
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               if (dist[j][i] == 0) cout << '*' << ' ';
               else cout << dist[j][i] << ' ';
           }
           cout << '\n';
       }
       cout << '\n';*/

    if (dist[c2][r2] == 0) {
        cout << -1;
    }
    else {
        cout << dist[c2][r2] - 1;
    }

}

