#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
string name[1005];
unordered_map<string, int> id; // key(이름), vaule(숫자)

int deg[1005];
vector<int> adj[1005];
vector<int> ch[1005];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> name[i];
	sort(name + 1, name + 1 + n);

	for (int i = 1; i <= n; i++) 
		id[name[i]] = i;	// id[key] = value;

	cin >> m;
	while (m--) {
		string a, b;
		cin >> a >> b;
		adj[id[b]].push_back(id[a]);
		deg[id[a]]++;
	}

	// 시조 저장 후 출력
	vector<int> ac;
	for (int i = 1; i <= n; i++) if (!deg[i]) ac.push_back(i);
	cout << ac.size() << '\n';
	for (int e : ac) cout << name[e] << ' ';
	cout << '\n';

	// indegree(deg)가 1 많은 후손(자녀)들의 정보를 배열 ch에 저장
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
		// 조상과 후손의 세대 차이가 1인 경우 자신의 부모
		// 조상 deg - 후손 deg == 1
		for (int e : adj[i])
			if (deg[e] - deg[i] == 1) ch[i].push_back(e);
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		int sz = ch[i].size();
		cout << name[i] << ' ' << sz << ' ';
		for (int e: ch[i]) cout << name[e] << ' ';
		cout << '\n';
	}

	return 0;
}
