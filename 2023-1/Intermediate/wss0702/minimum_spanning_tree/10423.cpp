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
#define MAX 100005
using namespace std;
int v, e, k;
int ele[1005];
vector<pair<long long, int>>adj[MAX];//cost, v_2
priority_queue< tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
bool check[MAX];//최소신장 트리에 포함되었는가?
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e >> k;
	for (int i = 0; i < k; i++) {
		cin >> ele[i];
	}
	for (int i = 0; i < e; i++) {
		int v_1, v_2, cost;
		cin >> v_1 >> v_2 >> cost;
		adj[v_1].push_back({ cost,v_2 });
		adj[v_2].push_back({ cost,v_1 });
	}
	int cnt = 0;
	long long ans = 0;
	for (int i = 0; i < k; i++) {
		check[ele[i]] = 1;
		for (auto next : adj[ele[i]]) pq.push({ next.X, ele[i], next.Y });
	}
	if (k != 1) {
		while (!pq.empty()) {
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
	}
	else {
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
	}
	cout << ans;
}
