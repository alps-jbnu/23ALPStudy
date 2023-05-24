#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 

int n, m; // n : 세로 크기, m : 가로 크기
bool b[102][102]; // 벽 정보를 저장할 배열
int d[102][102]; // 해당 지점까지의 최소 거리를 저장할 배열

int dx[] = {1, 0, -1, 0}; // 이동할 수 있는 x좌표의 변화량
int dy[] = {0, 1, 0, -1}; // 이동할 수 있는 y좌표의 변화량

int solve(){ // 다익스트라 알고리즘으로 최단 거리를 구하는 함수
  priority_queue< tuple<int, int, int>, 
                  vector<tuple<int, int, int>>,
                  greater<tuple<int, int, int>> > pq;
  d[1][1] = 0; // 시작 위치의 최소 거리를 0으로 설정
  pq.push({0, 1, 1}); // 시작 위치와 최소 거리 0을 우선순위 큐에 넣는다.
  while(!pq.empty()){ // 우선순위 큐가 비어있을 때까지 반복.
    int cw, cx, cy; // 현재 위치의 최소 거리, x좌표, y좌표
    tie(cw, cx, cy) = pq.top(); pq.pop(); // 우선순위 큐에서 최소 거리의 위치를 꺼낸다.
    if(d[cx][cy] != cw) continue; // 현재 위치의 최소 거리가 이미 갱신되어 있으면 넘어감.

    for(int dir = 0; dir < 4; dir++) { // 상하좌우 방향을 순회한다.
      int nx = cx + dx[dir]; // 이동할 x좌표
      int ny = cy + dy[dir]; // 이동할 y좌표
      if(nx > n || nx < 1) continue; // 이동할 위치가 범위를 벗어나면 넘어감.
      if(ny > m || ny < 1) continue;
      int nw = cw + b[nx][ny]; // 이동할 위치가 벽인 경우 비용을 1 추가.
      if(nw < d[nx][ny]) { // 이동할 위치의 최소 거리가 갱신될 수 있는 경우
        d[nx][ny] = nw; // 최소 거리를 갱신하고
        pq.push({nw, nx, ny}); // 우선순위 큐에 넣는다.
      }
    }
  }
  return d[n][m]; // 도착 지점의 최소 거리를 반환.
}

int main(void){
  ios::sync_with_stdio(0);  
  cin.tie(0);

  cin >> m >> n;  // 세로 길이 n, 가로 길이 m을 입력받음
  for(int i = 1; i <= n; i++){  // 벽 정보 입력받음
    string str; cin >> str;
    for(int j = 1; j <= m; j++)
      b[i][j] = str[j-1] - '0';  // char -> int 변환 후 b 배열에 저장
  }
  for(int i = 1; i <= n; i++)
    fill(d[i] + 1, d[i] + m + 1, INF);  // 거리 배열 d를 INF로 초기화

  cout << solve();  // 최소 비용 출력
}
