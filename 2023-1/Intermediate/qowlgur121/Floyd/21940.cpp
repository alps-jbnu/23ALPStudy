#include <bits/stdc++.h>
using namespace std;

const int INF = 987987987; 

int n, m, f; // 도시의 개수, 버스 노선의 개수, 친구의 수
int c[202]; // 친구들이 사는 도시의 번호를 저장할 배열 c
int d[202][202]; // 최소 비용을 저장할 배열 d

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // 도시의 개수와 버스 노선의 개수를 입력
    for (int i = 1; i <= n; i++) { // 2차원 배열 d의 모든 값에 INF 초기화
        fill(d[i], d[i] + n + 1, INF);
        d[i][i] = 0; // 자기 자신으로 가는 비용은 0으로 설정
    }

    int x, y, cost;
    while (m--) { // 버스 노선의 개수만큼 반복
        cin >> x >> y >> cost; // 출발 도시, 도착 도시, 비용을 입력
        d[x][y] = min(d[x][y], cost); // x에서 y로 가는 비용이 더 작을 경우 최소 비용을 업데이트
    }
    cin >> f; // 친구의 수를 입력
    for (int ci = 1; ci <= f; ci++) { // 친구의 수만큼 반복
        cin >> x;
        c[ci] = x; // 친구들이 사는 도시의 번호를 입력받아 배열 c에 저장
    }
    for (int k = 1; k <= n; k++) // 플로이드 알고리즘을 이용해 모든 도시 쌍 사이의 최소 비용을 구함
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);

    vector<pair<int, int>> v; // 도시의 번호와 해당 도시로부터 친구들이 모이는 데 필요한 최소 비용을 저장할 벡터 v를 선언
    for (int i = 1; i <= n; i++) { // 모든 도시에 대해 반복
        int mx = 0; // 최소 비용을 구하기 위해 mx를 0으로 초기화
        for (int ci = 1; ci <= f; ci++) // 모든 친구에 대해 반복
            mx = max(mx, d[i][c[ci]] + d[c[ci]][i]); // 현재 도시에서 친구들이 모이는 데 필요한 최대 비용을 구함
        v.push_back({ mx, i }); // 도시 번호와 최소 비용을 벡터 v에 추가
    }
    sort(v.begin(), v.end()); // 최소 비용을 기준으로 벡터 v를 오름차순으로 정렬

    int mn = v[0].first; 
    for (auto cur : v) { // 정렬된 벡터 v를 순회
        if (mn < cur.first) break; // 만약 현재 도시의 최소 비용이 가장 작은 최소 비용보다 크면 반복문을 종료.
        cout << cur.second << ' '; // 그렇지 않으면 현재 도시의 번호를 출력.
    }
}
