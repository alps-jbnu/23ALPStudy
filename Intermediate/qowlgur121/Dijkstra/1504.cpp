#include <bits/stdc++.h>    
using namespace std;         

typedef long long ll;       // long long 자료형에 대한 별칭을 ll로 지정

const int INF = 0x3f3f3f3f;  

int n, m;                   // 정점의 수 n과 간선의 수 m
int d[802];                 // 시작점으로부터의 최단 거리를 저장할 배열
vector<pair<int,int>> adj[802];  // 인접 리스트를 저장할 벡터

// st에서 en으로 가는 최단 거리를 계산하는 함수
ll solve(int st, int en){

  // 최소 힙을 구성하는 우선순위 큐를 선언
  priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

  fill(d, d + n + 1, INF);  // 배열 d를 INF로 초기화
  d[st] = 0;                // 시작점으로부터의 거리를 0으로 설정
  pq.push({d[st], st});     // 시작점을 큐에 삽입

  while(!pq.empty()){       // 큐가 비어있지 않은 동안
    int u, v, w, dw;
    tie(w, u) = pq.top(); pq.pop();  // 현재까지 가장 가까운 정점을 꺼냄
    if(d[u] != w) continue;  // 이미 더 짧은 경로가 있다면 스킵
    for(auto nxt : adj[u]){  // 모든 인접한 정점에 대해
      tie(dw, v) = nxt;
      dw += w;               // 가중치를 누적하여 최단 거리를 갱신
      if(dw < d[v]) {        // 누적 거리가 더 짧다면
        d[v] = dw;           // 거리를 갱신하고
        pq.push({dw, v});    // 해당 정점을 큐에 삽입
      }
    }
  }
  return d[en];  // 목적지까지의 최단 거리 반환
}

int main(){
    
// 입력
cin >> n >> m;

    int a, b, c;
    while(m--){
        cin >> a >> b >> c;
        adj[a].push_back({c, b}); // a와 b를 연결하는 가중치 c의 간선을 추가한다.
        adj[b].push_back({c, a}); // b와 a를 연결하는 가중치 c의 간선도 추가한다. (무방향 그래프이기 때문)
    }
// 목적지 노드 e1, e2를 입력받는다.
    int e1, e2;
    cin >> e1 >> e2;

// ans1: 1 -> e1 -> e2 -> n 경로를 따를 경우의 최단 거리
// ans2: 1 -> e2 -> e1 -> n 경로를 따를 경우의 최단 거리
// ans: ans1과 ans2 중 더 작은 값이 최종 정답이 된다.
    ll ans1 = solve(1, e1) + solve(e1, e2) + solve(e2, n);
    ll ans2 = solve(1, e2) + solve(e2, e1) + solve(e1, n);
    ll ans = min(ans1, ans2);

// ans가 초기값 INF(최대값)보다 크거나 같으면, 이는 경로가 없다는 뜻이므로 -1을 출력한다.
    if(ans >= INF) ans = -1;

    cout << ans;
    return 0;
}
