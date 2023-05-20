#include <bits/stdc++.h> 
using namespace std;

int n, m, r; // 지역의 개수, 이동 가능한 최대 거리, 길의 개수
const int INF = 987987987;

int item[102]; // 각 지역에서 모을 수 있는 아이템의 개수
bool vis[102]; // 각 지역이 유저에 의해 방문되었는지를 나타내는 배열

int d[102][102]; // 각 지역간의 최단 거리를 저장하는 배열
int nxt[102][102]; // 최단 거리 경로에서 다음으로 이동해야 할 지점을 저장하는 배열

void visit(int i, int j) { // 최단 경로를 방문하며 vis 배열을 갱신하는 함수
    int cur = i;
    while (cur != j) { // i부터 j까지의 최단 경로를 찾기 위해 nxt 배열을 사용함.
        vis[cur] = 1;
        cur = nxt[cur][j];
    }
    vis[j] = 1;
}

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0);


    cin >> n >> m >> r;

    // 각 지역의 아이템 수 입력 받기
    for (int i = 1; i <= n; i++) {
        int sc; cin >> sc;
        item[i] = sc;
    }

    // 플로이드 와샬 알고리즘을 위해 d 배열 초기화
    for (int i = 1; i <= n; i++) {
        fill(d[i], d[i] + n + 1, INF);
        d[i][i] = 0;
    }

    // 양방향 간선 입력 받기
    int x, y, dist;
    while (r--) {
        cin >> x >> y >> dist;
        d[x][y] = dist; d[y][x] = dist;
        nxt[x][y] = y; nxt[y][x] = x;
    }

    // 플로이드 와샬 알고리즘 수행
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                int tmp = d[i][k] + d[k][j];
                if (tmp < d[i][j]) {
                    d[i][j] = tmp;
                    nxt[i][j] = nxt[i][k];
                }
            }

    // 각 지역에서 모든 지역까지의 거리를 계산하고 아이템을 수집
    int ans = 0, tmp;
    for (int i = 1; i <= n; i++) {
        tmp = 0;
        fill(vis + 1, vis + n + 1, 0);

        for (int j = 1; j <= n; j++) {

            // 거리가 m 이하인 지역을 방문
            if (d[i][j] > m) continue;

            // i부터 j까지의 경로상에 있는 지역들을 방문
            visit(i, j);
        }

        // 방문한 지역의 아이템을 수집
        for (int j = 1; j <= n; j++)
            if (vis[j]) tmp += item[j];

        // 아이템 수의 최댓값 구하기
        ans = max(ans, tmp);
    }

    // 결과 출력
    cout << ans;

}
