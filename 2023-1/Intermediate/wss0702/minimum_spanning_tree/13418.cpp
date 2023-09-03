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
#define MAX 1000002
using namespace std;
int v, e;
int testcase;
vector<pair<int, int>>adj[MAX]; //cost, v_2
vector<pair<int, int>>adj_copy[MAX];
priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq_copy;
bool check[MAX];//최소신장 트리에 포함되었는가?
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i <= e; i++){
		int cost;//0이면 오르막길/1이면 내리막길
		int v_1, v_2;
		cin >> v_1 >> v_2 >> cost;
		
		adj[v_1].push_back({ cost,v_2 });
		adj[v_2].push_back({ cost,v_1 });
		if (cost == 0) {
			adj_copy[v_1].push_back({ 2,v_2 });
			adj_copy[v_2].push_back({ 2,v_1 });
		}
		else {
			adj_copy[v_1].push_back({ cost,v_2 });
			adj_copy[v_2].push_back({ cost,v_1 });
		}
	}
	int cnt = 0;
	int ans = 0;
	int max_cost = 0;
	int min_cost = 0;
	int high_way_cnt = 0;
	check[0] = 1;
	for (auto next : adj[0]) pq.push({ next.X,0,next.Y });
	while (cnt < v) {
		int cost;
		int v_1, v_2;
		tie(cost, v_1, v_2) = pq.top(); pq.pop();
		if (check[v_2])continue;
		if (cost == 0) {
			high_way_cnt++;
			max_cost = high_way_cnt * high_way_cnt;
		}
		check[v_2] = 1;
		cnt++;
		for (auto next : adj[v_2]) {
			if (!check[next.Y])pq.push({ next.X,v_2,next.Y });
		}
	}
	high_way_cnt = 0;
	cnt = 0;
	fill(check, check + v + 1, false);
	check[0] = 1;
	for (auto next : adj_copy[0]) pq_copy.push({ next.X,0,next.Y });
	while (cnt < v) {
		int cost;
		int v_1, v_2;
		tie(cost, v_1, v_2) = pq_copy.top(); pq_copy.pop();
		if (check[v_2])continue;
		if (cost == 2) {
			high_way_cnt++;
			min_cost = high_way_cnt * high_way_cnt;
		}
		check[v_2] = 1;
		cnt++;
		for (auto next : adj_copy[v_2]) {
			if (!check[next.Y])pq_copy.push({ next.X,v_2,next.Y });
		}
	}
	cout << max_cost - min_cost;
}
