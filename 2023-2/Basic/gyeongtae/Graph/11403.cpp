#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
int map[101][101];

void bfs() {
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				if (map[i][k]==1 && map[k][j]==1) {
					map[i][j] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	int a, b;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> map[i][j];
		}
	}

	bfs();

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
