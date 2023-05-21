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
vector<pair<long long, int>>adj[MAX];//cost, v_2
priority_queue< tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
bool check[MAX];//최소신장 트리에 포함되었는가?
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			long long cost;
			cin >> cost;
			if (i == j) continue;
			adj[i].push_back({ cost,j });

		}
	}
	int cnt = 0;
	long long ans = 0;
	check[1] = 1;
	for (auto next : adj[1]) pq.push({ next.X,1,next.Y });
	while (cnt < v - 1) {
		long long cost;
		int v_1, v_2;
		tie(cost, v_1, v_2) = pq.top(); pq.pop();
		if (check[v_2])continue;
		ans += cost;
		check[v_2] = 1;
		cnt++;
		for (auto next : adj[v_2]) {
			if (!check[next.Y])pq.push({ next.X,v_2,next.Y });
		}
	}
	cout << ans;
		
	
}
