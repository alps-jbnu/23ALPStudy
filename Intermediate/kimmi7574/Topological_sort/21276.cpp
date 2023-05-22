#include <bits/stdc++.h>
using namespace std;

map<string, int> idx;
map<int, string> name_map;

int in_degree[1001];
vector<int> adj[1001];
vector<int> children[1001];

vector<string> ancestor;

void topologySort(string anc) {
	queue<int> q;
	q.push(idx[anc]);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto next : adj[cur]) {
			in_degree[next]--;
			if (in_degree[next] == 0) {
				children[cur].push_back(next);
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string name;
	int n, m, k;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> name;
		idx[name] = i;	//name-i번 (짝 지어줌)
		name_map[i] = name;
	}

	cin >> m;
	for (int i = 0; i < n; i++) {
		string cur_name, prev_name;
		cin >> cur_name >> prev_name;
		int cur = idx[cur_name];
		int prev = idx[prev_name];

		adj[prev].push_back(cur);
		in_degree[cur]++;
	}

	for (int i = 0; i < n; i++)
		if (in_degree[i] == 0)
			ancestor.push_back(name_map[i]);

	sort(ancestor.begin(), ancestor.end());
	
	for (auto a : ancestor)
		topologySort(a);
	
	//조상 수와 정보 출력
	cout << ancestor.size() << "\n";
	for (auto a : ancestor)
		cout << a << " ";
	cout << "\n";

	//자식 정보와 수 출력
	for (auto i: idx) {
		cout << i.first << " " << children[i.second].size() << " ";
		
		vector<string> vec;
		for (auto next : children[i.second])
			vec.push_back(name_map[next]);

		sort(vec.begin(), vec.end());

		for (auto elmt : vec)
			cout << elmt << " ";
		cout << "\n";
	}

	return 0;
}