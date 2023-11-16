#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
int map[101][101];
int vis[101];
int num[101][101];
vector <pair<int,int>> v;
int s = 9999999;
int ans;


void bfs(int x) {
	vis[x] = 1;
	queue <int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 1;i <= n;i++) {
			if (map[x][i] == 1&&vis[i]==0) {
				vis[i] =vis[x] +1;				
				q.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		cin >> a >> b;
		map[a][b]=1;
		map[b][a]=1;
	}
	for (int i = 1;i <= n;i++) {
		for (int i = 1;i <= m;i++) {
			vis[i] = 0;
		}
		bfs(i);
		int sum = 0;
		for (int j = 1;j <= n;j++) {
			if (i == j) {
				continue;
			}
			else {
				sum += vis[j] - 1;
			}
		}
		if (sum < s) {
			s = sum;
			ans = i;
		}

	}
	cout << ans;
}
