#include <bits/stdc++.h>
using namespace std;

int n,k;
int dist[200002];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  int MX = 200000;
  fill(dist,dist+MX,-1);
  deque<int> dq;
  dq.push_back(n);
  dist[n]=0;
  while(!dq.empty()){
    int cur = dq.front(); dq.pop_front();
    if( 2*cur < MX && dist[2*cur] == -1){
      dist[2*cur] = dist[cur];
      dq.push_front(2*cur);
    }
    for(int nxt : {cur-1,cur+1}){ //앞 뒤 이동을 덱에 넣음으로서 BFS 구현
      if(nxt < 0 or nxt >= MX or dist[nxt] != -1) continue;
      dist[nxt] = dist[cur]+1;
      dq.push_back(nxt);      
    }
  } 
  cout << dist[k];
}
