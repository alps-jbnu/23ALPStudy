#include <iostream>
#include <vector>
using namespace std;

int n;
int map[22][22];

int cut(int sx, int sy, int ex, int ey, int dir) {
	vector<pair<int, int>> v;
	int tmp = 0;
	for(int i=sx; i<=ex; i++)
		for (int j = sy; j <= ey; j++) {
			if (map[i][j] == 1) v.push_back({ i,j });
			else tmp += map[i][j];
		}

	if (tmp == 0) return 0;						// 보물 없음
	else if (tmp == 2 && !v.size()) return 1;	// 보물 하나만
	// 이 조건은 왜 넣은거지?
	else if (!v.size()) return 0;				// 불순물 없음 (보석 여러개?)

	// 그 외 - 불순물 존재, 보석 여러개 등
	int result = 0;
	if (!dir) {
		for (pair<int, int> t : v) {
			int x = t.first;
			int y = t.second;
			int tp = 0;
			for (int i = sx; i <= ex; i++) tp += map[i][y];
			if (tp == 1) result += cut(sx, sy, ex, y - 1, 1) * cut(sx, y + 1, ex, ey, 1);
		}
	}
	if (dir) {
		for (pair<int, int> t : v) {
			int x = t.first;
			int y = t.second;
			int tp = 0;
			for (int i = sy; i <= ey; i++) tp += map[x][i];
			if (tp == 1) result += cut(sx, sy, x - 1, ey, 0) * cut(x + 1, sy, ex, ey, 0);
		}
	}
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> map[i][j];

	int ans = 0;
	ans += cut(0, 0, n - 1, n - 1, 0);
	ans += cut(0, 0, n - 1, n - 1, 1);
	if (ans == 0)   ans = -1;
	cout << ans << '\n';

	return 0;
}
