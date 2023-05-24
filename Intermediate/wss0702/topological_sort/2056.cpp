#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<array>
#include<vector>
#include<string.h>
#include<unordered_map>
#define MAX 10005
using namespace std;
int v, e, k;
int ans;
int indegree[MAX];
int cost[MAX];
vector<int> adj[MAX];
vector<int> time_table[1000005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> e;
	for (int i = 1; i <= e; i++) {
		cin >> cost[i];
		int work_cnt;
		cin >> work_cnt;
		if (!work_cnt)time_table[cost[i]].push_back(i);
		while (work_cnt--) {
			int x; 
			cin >> x;
			adj[x].push_back(i);
			indegree[i]++;
		}
	}
	for (int i = 0; i <= 1000000; i++) {
		for (int fin : time_table[i]) {
			ans = i;
			for (int nxt : adj[fin]) {
				indegree[nxt]--;
				if (indegree[nxt] != 0) continue;
				time_table[i + cost[nxt]].push_back(nxt);
			}
		}
	}
	cout << ans;
}

