#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int s = 0;
int map[101][101] = { 0, };
bool vis[101] = { 0, };
queue <int> q;

void bfs(int a) {
	q.push(a);
	vis[a] =true;

	while (!q.empty()) {
		a = q.front();
		q.pop();

		for (int i = 1;i <= n;i++) {
			if (map[a][i] == 1 && vis[i] == 0) {
				q.push(i);				
				vis[i] = true;
				s++;
			}
		}
	}
}

int main() {
	int c, d;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> c >> d;
		map[c][d] = 1;
		map[d][c] = 1;
	}

	bfs(1);

	cout << s;
}
