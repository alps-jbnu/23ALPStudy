#include <bits/stdc++.h> 
using namespace std;

const int INF = 987987987;

int v, e; 
int d[402][402]; // 각 정점간 최단 거리를 저장할 배열

int main(void) {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> v >> e; // 정점의 개수와 간선의 개수 입력
    for (int i = 1; i <= v; i++) {
        fill(d[i] + 1, d[i] + v + 1, INF); 
        d[i][i] = 0; // 자기 자신까지의 거리는 0
    }

    int a, b, c;
    while (e--) { // 간선 정보 입력
        cin >> a >> b >> c;
        d[a][b] = c; // a에서 b로 가는 가중치 c의 간선이 있다는 정보 입력
    }

    for (int k = 1; k <= v; k++) 
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // 더 작은 거리로 갱신

    int ans = INF; // 사이클의 최소 길이
    for (int i = 1; i <= v; i++)
        for (int j = i + 1; j <= v; j++)
            ans = min(ans, d[i][j] + d[j][i]); // 사이클의 최소 길이 갱신

    if (ans == INF) ans = -1; // 사이클이 없으면 -1 출력
    cout << ans; // 정답 출력
}
