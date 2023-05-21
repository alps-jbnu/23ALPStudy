#include<bits/stdc++.h>
using namespace std;

int n;
int total = 0;

int par[101];
vector<pair<int, pair<int, int>>> edge;

int Find(int a) {
	if (par[a] == a)	return a;
	return par[a] = Find(par[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a > b)	par[a] = b;
	else par[b] = a;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	char c;
	int cost;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c;
			if (c >= 'a' && c <= 'z') {
				cost = c - 'a' + 1;
				edge.push_back({ cost,{i,j} });
				total += cost;
			}
			else if (c >= 'A' && c <= 'Z') {
				cost = c - 'A' + 27;
				edge.push_back({ cost,{i,j} });
				total += cost;
			}
		}
	}

	for (int i = 1; i <= n; i++)	par[i] = i;
	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++) {
		int a, b, c;
		a = edge[i].first;
		b = edge[i].second.first;
		c = edge[i].second.second;
		
		if (Find(b) != Find(c)) {
			Union(b, c);
			total -= a;
		}
	}
	int p = Find(1);
	for (int i = 2; i <= n; i++) {
		if (Find(i) != p) {
			cout << -1;
			return 0;
		}
	}
	cout << total;
 }