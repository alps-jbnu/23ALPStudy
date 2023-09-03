#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101];
bool b[101][101];
int n,m;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int solve() {
    priority_queue< tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
    d[1][1] = 0;
    pq.push({0,1,1});  //비용, i, j
    while(!pq.empty()) {
        int cost, x, y;
        tie(cost,x,y) = pq.top();
        pq.pop();
        if(d[x][y] != cost) continue; // 거리가 d에 있는 값과 다를 경우 넘어감
        for(int dir = 0; dir<4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx > n || nx < 1) continue; //범위밖 넘어감
            if(ny > m || ny < 1) continue;
            int ncost = cost + b[nx][ny];
            if(ncost < d[nx][ny]) {
                d[nx][ny] = ncost;
                pq.push({ncost,nx,ny});
            }
        }
    }
    return d[n][m];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i=1; i<=n; i++) {
        string str;
        cin >> str;
        for(int j=1; j<=m; j++) {
            b[i][j] = str[j-1] - '0';  //1이면 갈 수있음 0이면 갈 수없음
        }
    }
    for(int i=1; i<=n; i++)
        fill(d[i] + 1, d[i] + m + 1, INF);

    cout << solve();

}