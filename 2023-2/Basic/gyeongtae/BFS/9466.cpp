#include <iostream> 
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, cnt;
int map[100001];
bool done[100001];
bool vis[100001];

void dfs(int x) {
	vis[x] = true;
	int s = map[x];
	if (vis[s] == 0) {
		dfs(s);
	}
	else {
		if (done[s] == 0) {
			for (int i = s;i != x;i = map[i]) {
				cnt++;
			}
			cnt++;
		}
	}
	done[x] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;
	cin >> a;
	for (int k = 0;k < a;k++) {
		cin >> b;
		cnt = 0;
		for (int i = 1;i <= b;i++) {
			vis[i] = 0;
			map[i] = 0;
			done[i] = 0;
		}
		for (int i = 1;i <= b;i++) {
			cin >> map[i];
		}
		for (int i = 1;i <= b;i++) {
			if (vis[i] == false) {
				dfs(i);
			}
		}
		cout <<  b - cnt << "\n";
	}
}
