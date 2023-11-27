#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;

#define X first
#define Y second


int n;

const int MX = 100'000;

int p[MX + 2]; 
pair<int, int> x[MX + 2];
pair<int, int> y[MX + 2];
pair<int, int> z[MX + 2];

vector<pair<int,int>> adj[100005];

int chk[100005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) {
	    int cx,cy,cz;
	    cin>>cx>>cy>>cz;
	    x[i] = {cx, i}; y[i] = {cy, i}; z[i] = {cz, i};
    }
      
    sort(x, x + n);
    sort(y, y + n);
    sort(z, z + n);
      
    for(int i = 1; i < n; i++) {
        int a = x[i].Y; int b = x[i-1].Y;
        int c = y[i].Y; int d = y[i-1].Y;
        int e = z[i].Y; int f = z[i-1].Y;
        adj[a].push_back({abs(x[i - 1].X - x[i].X), b});
        adj[b].push_back({abs(x[i - 1].X - x[i].X), a});
        adj[c].push_back({abs(y[i - 1].X - y[i].X), d});
        adj[d].push_back({abs(y[i - 1].X - y[i].X), c});
        adj[e].push_back({abs(z[i - 1].X - z[i].X), f});
        adj[f].push_back({abs(z[i - 1].X - z[i].X), e});
    }
    
    int cnt = 0; // 현재 선택된 간선의 수
  	int ans = 0;
  	// tuple<int,int,int> : {비용, 정점 1, 정점 2}
  	priority_queue< tuple<int,int,int>,
                  vector<tuple<int,int,int>>,
                  greater<tuple<int,int,int>> > pq;
                  
    chk[1] = 1;
    for(auto nxt : adj[1]) pq.push({nxt.X, 1, nxt.Y}); // 비용, 정점1, 정점2
    
    while(cnt < n-1) {
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		if(chk[b]) continue;
		ans += cost;
		chk[b] = 1;
		cnt++;
		for(auto nxt : adj[b]) {
			if(!chk[nxt.Y]) pq.push({nxt.X, b, nxt.Y});
		}
	} 
	
	cout << ans;

	return 0;
}
