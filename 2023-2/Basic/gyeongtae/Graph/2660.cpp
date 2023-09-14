#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n=0, m=0, a;
int map[51][51];
int vis[51];
queue <int> q;
int s = 0;
vector <pair<int,int>> v;
vector <int> v1;

int bfs(int b1) {
	fill(vis, vis + 51, 0);
	q.push(b1);
	vis[b1] = 1;
	int c = 0;
	while (!q.empty()) {
		int b = q.front();
		q.pop();

		c = max(c, vis[b]);
		for (int i=1;i <= a;i++) {
			if (!vis[i]&&map[b][i]==1) {
				vis[i]= vis[b] + 1;
				q.push(i);
				//cout << i <<" "<<b<<" "<<s<< "i와b와s\n";
			}
		}
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a;
	while (m!=-1&&n!=-1) {
		cin >> m >> n;
		map[n][m] = 1;
		map[m][n] = 1;
	}

	for (int i = 1;i <= a;i++) {
		int z=bfs(i);
		v.push_back(make_pair(z,i));
		s = 0;
		//cout << "지나감\n";
	}
	sort(v.begin(), v.end());
	int min1 = v[0].first;
	for (int i = 0;i < v.size();i++) {
		if (min1 == v[i].first) {
			v1.push_back(v[i].second);
		}
		//cout <<v[i].first<<" "<< v[i].second << "\n";
	}
	cout << min1 -1 << " " << v1.size() << "\n";
	for (int i = 0;i < v1.size();i++) {
		cout << v1[i] << " ";
	}

}
