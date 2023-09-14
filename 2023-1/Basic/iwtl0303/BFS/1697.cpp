#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dist[100002];            

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n,k;
  cin>>n>>k;
  fill(dist,dist+100001,-1);
  dist[n] = 0;
  queue<int> Q;
  Q.push(n);
  while(dist[k] == -1){
    int cur = Q.front(); Q.pop();
    for(int nxt : {cur-1,cur+1,cur*2}){   //좌,우,2배 이동
      if (nxt < 0 || nxt > 100000) continue; //범위 이탈
      if (dist[nxt] != -1) continue;         //이미 도달
      dist[nxt] = dist[cur] +1;
      Q.push(nxt);
    }
  }
  cout << dist[k];
}
