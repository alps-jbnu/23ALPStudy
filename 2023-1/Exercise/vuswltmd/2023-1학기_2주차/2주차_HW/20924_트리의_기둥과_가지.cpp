#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N, R, G;
vector<pair<int, int>> adj[200'005];
int p[200'005];
int depth[200'005];
int root_to_giga = 0;
int giga_to_leaf = 0;
stack<int> s2;
stack<int> s;
int _max = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> N >> R;

	for (int i = 0; i < N - 1; i++) {
		int a, b, d;

		cin >> a >> b >> d;

		adj[a].push_back({ b, d });
		adj[b].push_back({ a, d });
	}

	s.push(R);

	while (!s.empty()) {
		bool flag = false;
		int cur = s.top(); s.pop();

		for (auto nxt : adj[cur]) {
			if (p[cur] == nxt.first) continue;
			if (adj[cur].size() > 2) {
				G = cur;
				flag = true;
				break;
			}
			if (adj[cur].size() == 2 && p[cur] == 0) {
				G = cur;
				flag = true;
				break;
			}
			s.push(nxt.first);
			p[nxt.first] = cur;
			root_to_giga += nxt.second;
		}

		if (flag == true) {
			break;
		}
	}

	s2.push(G);
	while (!s2.empty()) {
		int cur = s2.top(); s2.pop();

		for (auto nxt : adj[cur]) {
			if (p[cur] == nxt.first) continue;
			s2.push(nxt.first);
			p[nxt.first] = cur;
			depth[nxt.first] = depth[cur] + nxt.second;
			_max = max(_max, depth[nxt.first]);
		}
	}

	//sort(depth, depth + 200'005);
	//reverse(depth, depth + 200'005);

	//for (int i = 0; i <= N; i++) {
	//	cout << depth[i] << ' ';
	//}
	//cout << endl;
	cout << root_to_giga << ' ' << _max;
}
