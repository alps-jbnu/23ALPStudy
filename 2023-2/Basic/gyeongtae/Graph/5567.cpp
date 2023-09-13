#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
int map[501][501];
bool vis[501];
queue <int> q;
int s = 0;

void bfs(int x) {
	vis[x] = true;
	q.push(x);

	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x != 1) {
			for (int i = 2;i <= m;i++) {
				if (map[x][i] == 1 && vis[i] == 0) {
					vis[i] = true;
					s++;
					continue;
				}
			}
		}
		else {
			for (int i = 1;i <= m;i++) {
				if (map[1][i] == 1 && vis[i] == 0) {
					vis[i] = true;
					q.push(i);
					s++;
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	int a, b;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	bfs(1);

	cout << s;
}
