#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, h;
int map[51][51] = { 0, };
bool visited[51][51] = { 0, };
int dy[] = { 0,0,-1,1 };
int dx[] = { 1,-1,0,0 };
queue<pair<int, int>> q;           //BFS 사용 큐
//vector<int> v;                    //그림 개수 저장 벡터
int s = 1;                        //그림 넓이

void BFS(int y, int x) {
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (map[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = true;
                s++;
                q.push(make_pair(ny, nx));
            }
        }
    }
}


int main() {
    cin >> h;
    for (int x = 0;x < h;x++) {
        cin >> m >> n >> k;
        int a, b;
        for (int i = 0;i < k;i++) {
            cin >> a >> b;
            map[b][a] = 1;
        }


        int cnt = 0;   //영역 개수
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) {
                    BFS(i, j);
                    //v.push_back(s);
                    cnt++;
                    s = 1;
                }
            }
        }

        cout << cnt << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }
}
