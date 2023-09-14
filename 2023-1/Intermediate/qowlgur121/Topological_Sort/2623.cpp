#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, T, num, one, inDegree[1001];
vector<int> v[1001], result;
queue<int> q;

void input() {
	cin >> N >> M;	
	for (int i = 0; i < M; i++) {
		cin >> T;
		cin >> one;
		for (int j = 1; j < T; j++) {
			cin >> num;
			v[one].push_back(num);
			inDegree[num]++;
			one = num;	//1 2 3  1-2 2-3 과정
		}
	}
}

void topologySort() {
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		result.push_back(x);

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			inDegree[nx]--;
			if (inDegree[nx] == 0)
				q.push(nx);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	input();

	topologySort();

	if (result.size() == N) {
		for (auto c : result)
			cout << c << "\n";
	}
	else
		cout << 0;
}
