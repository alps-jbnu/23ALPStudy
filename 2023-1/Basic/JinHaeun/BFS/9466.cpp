#include <bits/stdc++.h>
using namespace std;

int hope[100005];
int n;
int visit[100005]; 

const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x) {
  	int cur = x;
  	while(true)	{
    	visit[cur] = x;
    	cur = hope[cur];
    	  	
    	if(visit[cur] == x) {
    	  	while(visit[cur] != CYCLE_IN) {
        		visit[cur] = CYCLE_IN;
        		cur = hope[cur];
      		}
      		return;
    	}
    	
    	else if(visit[cur] != 0) 
			return;
  	}
}

int main(void) {
  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	int t;
  	cin >> t;
  	
  	while(t--) {
    	cin >> n;
    	fill(visit+1, visit+n+1, 0); //방문안함표시  
    	
    	for(int i = 1; i <= n; i++)
    	  cin >> hope[i];     //원하는 학생 
    	  
    	int ans = 0;
    	
    	for(int i = 1; i <= n; i++){
    	  	if(visit[i] == NOT_VISITED) 
			  	run(i);
    	}
    	
    	int cnt = 0;
    	for(int i = 1; i <= n; i++){
    	  	if(visit[i] != CYCLE_IN) 
			  	cnt++;
    	}
    	
    	cout << cnt << '\n';
  	}
}
