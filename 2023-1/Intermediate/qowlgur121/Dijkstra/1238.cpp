#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
vector<pair<int,int>> adj[1002]; // 인접 리스트

// st에서 en까지의 최단 경로를 반환하는 함수
int solve(int st, int en){
  int d[1002];
  fill(d, d + n + 1, INF); // d 배열을 INF로 초기화
  priority_queue< pair<int,int>, // {거리, 정점번호}를 원소로 하는 우선순위 큐
                  vector<pair<int,int>>,
                  greater<pair<int,int>> > pq; // 오름차순으로 정렬되는 우선순위 큐
  d[st] = 0; // 시작점의 거리를 0으로 초기화
  pq.push({0, st}); // 우선순위 큐에 시작점을 삽입
  while(!pq.empty()){
    int u, v, w, dw;
    tie(w, u) = pq.top(); pq.pop(); // 우선순위 큐에서 가장 작은 거리를 가진 정점을 꺼냄
    if(d[u] != w) continue; // u에 대해 더 짧은 거리로 업데이트된 적이 있다면, 무시
    for(auto nxt : adj[u]){ // u에 인접한 정점들을 순회
      tie(dw, v) = nxt; // v는 u와 인접한 정점, dw는 u에서 v까지의 거리
      if(dw + w < d[v]) { // u를 거쳐서 v까지 가는 거리가 더 짧다면, 업데이트하고 큐에 삽입
        d[v] = dw + w;
        pq.push({d[v], v});
      }
    }
  }
  return d[en]; // en까지의 최단 거리를 반환
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int en;
  cin >> n >> m >> en; // 정점의 개수, 간선의 개수, 도착점

  int u, v, w;
  while(m--) {
    cin >> u >> v >> w; // 간선 정보를 입력받아 인접 리스트에 추가
    adj[u].push_back({w, v});
  }

  int ans = 0;
  for(int st = 1; st <= n; st++)
    ans = max(ans, solve(st, en) + solve(en, st)); // 모든 출발점에서 en까지의 최단 거리와 en에서 출발점까지의 최단 거리의 합 중 최댓값을 찾음
  cout << ans; // 결과 출력
}
