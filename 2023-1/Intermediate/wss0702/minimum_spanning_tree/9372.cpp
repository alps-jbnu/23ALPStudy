#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>
#include<tuple>
#include<array>
#include<vector>
#include<string.h>
#define X first
#define Y second
#define MAX 10005
using namespace std;
int v, e;
int testcase;

bool check[MAX];//최소신장 트리에 포함되었는가?
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> v >> e;
		vector<pair<long long, int>>adj[MAX];
		for (int j = 0; j < e; j++) {
			int cost = 1;
			int v_1, v_2;
			cin >> v_1 >> v_2;
			adj[v_1].push_back({ cost, v_2 });
			adj[v_2].push_back({ cost,v_1 });
		}
		priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		int cnt = 0;
		int ans = 0;
		check[1] = 1;
		for (auto next : adj[1]) pq.push({ next.X,1,next.Y });
		while (cnt < v - 1) {
			int cost, v_1, v_2;
			tie(cost, v_1, v_2) = pq.top(); pq.pop();
			if (check[v_2])continue;
			ans += cost;
			check[v_2] = 1;
			cnt++;
			for (auto next : adj[v_2]) {
				if (!check[next.Y])pq.push({ next.X,v_2,next.Y });
			}
		}
		cout << ans << "\n";
		fill(check, check + v + 1, false);
		
	}
}
