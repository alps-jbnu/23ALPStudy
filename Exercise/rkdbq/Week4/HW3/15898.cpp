#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, char> grid[5][5];
pair<int, char> sources[11][4][4][4]; // [idx][rotation][x][y]
bool is_visited[11];
int n, ans;

void grid_init() {
	for (int i{}; i < 5; i++) {
		for (int j{}; j < 5; j++) {
			grid[i][j] = { 0, 'W' };
		}
	}
}

int calculate_quality(pair<int, char> grid[5][5]) {
	int r, b, g, y;
	r = b = g = y = 0;
	for (int i{}; i < 5; i++) {
		for (int j{}; j < 5; j++) {
			if (grid[i][j].second == 'W') continue;
			else if (grid[i][j].second == 'R') r += grid[i][j].first;
			else if (grid[i][j].second == 'B') b += grid[i][j].first;
			else if (grid[i][j].second == 'G') g += grid[i][j].first;
			else if (grid[i][j].second == 'Y') y += grid[i][j].first;
		}
	}
	return 7 * r + 5 * b + 3 * g + 2 * y;
}

void func(pair<int, char> bef[5][5], int cur_src_idx, pair<int, int> st, int rotation, int level) {

	pair<int, char> source[4][4];
	for (int i{}; i < 4; i++) {
		for (int j{}; j < 4; j++) {
			source[i][j] = sources[cur_src_idx][rotation][i][j];
		}
	}

	pair<int, char> cur[5][5];
	for (int i{}; i < 5; i++) {
		for (int j{}; j < 5; j++) {
			cur[i][j] = bef[i][j];
		}
	}
	
	for (int i{ st.first }; i < st.first + 4; i++) {
		for (int j{ st.second }; j < st.second + 4; j++) {
			cur[i][j].first += source[i - st.first][j - st.second].first;
			if (cur[i][j].first < 0) cur[i][j].first = 0;
			if (cur[i][j].first > 9) cur[i][j].first = 9;
			if (source[i - st.first][j - st.second].second == 'W') continue;
			cur[i][j].second = source[i - st.first][j - st.second].second;
		}
	}

	if (level >= 3) {
		ans = max(ans, calculate_quality(cur));
		return;
	}

	for (int i{}; i < n; i++) {
		if (is_visited[i]) continue;

		is_visited[i] = true;
		for (int j{}; j < 4; j++) {
			func(cur, i, { 0, 0 }, j, level + 1);
			func(cur, i, { 0, 1 }, j, level + 1);
			func(cur, i, { 1, 0 }, j, level + 1);
			func(cur, i, { 1, 1 }, j, level + 1);
		}
		is_visited[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	grid_init();

	cin >> n;

	for (int i{}; i < n; i++) {
		for (int j{}; j < 4; j++) {
			for (int k{}; k < 4; k++) {
				cin >> sources[i][0][j][k].first;
			}
		}
		for (int j{}; j < 4; j++) {
			for (int k{}; k < 4; k++) {
				cin >> sources[i][0][j][k].second;
			}
		}
	}

	for (int idx{}; idx < n; idx++) {
		for (int rotation{ 1 }; rotation < 4; rotation++) {
			switch (rotation)
			{
			case 1:
				for (int i{}; i < 4; i++) {
					sources[idx][rotation][0][i] = sources[idx][0][i][3];
					sources[idx][rotation][i][0] = sources[idx][0][0][3 - i];
					sources[idx][rotation][3][i] = sources[idx][0][i][0];
					sources[idx][rotation][i][3] = sources[idx][0][3][3 - i];
				}
				sources[idx][rotation][1][1] = sources[idx][0][1][2];
				sources[idx][rotation][2][1] = sources[idx][0][1][1];
				sources[idx][rotation][2][2] = sources[idx][0][2][1];
				sources[idx][rotation][1][2] = sources[idx][0][2][2];
				break;
			case 2:
				for (int i{}; i < 4; i++) {
					sources[idx][rotation][0][i] = sources[idx][0][3][3 - i];
					sources[idx][rotation][i][0] = sources[idx][0][3 - i][3];
					sources[idx][rotation][3][i] = sources[idx][0][0][3 - i];
					sources[idx][rotation][i][3] = sources[idx][0][3 - i][0];
				}
				sources[idx][rotation][1][1] = sources[idx][0][2][2];
				sources[idx][rotation][2][1] = sources[idx][0][1][2];
				sources[idx][rotation][2][2] = sources[idx][0][1][1];
				sources[idx][rotation][1][2] = sources[idx][0][2][1];
				break;
			case 3:
				for (int i{}; i < 4; i++) {
					sources[idx][rotation][0][i] = sources[idx][0][3 - i][0];
					sources[idx][rotation][i][0] = sources[idx][0][3][i];
					sources[idx][rotation][3][i] = sources[idx][0][3 - i][3];
					sources[idx][rotation][i][3] = sources[idx][0][0][i];
				}
				sources[idx][rotation][1][1] = sources[idx][0][2][1];
				sources[idx][rotation][2][1] = sources[idx][0][2][2];
				sources[idx][rotation][2][2] = sources[idx][0][1][2];
				sources[idx][rotation][1][2] = sources[idx][0][1][1];
				break;
			default:
				break;
			}
		}
	}

	for (int i{}; i < n; i++) {
		is_visited[i] = true;
		for (int j{}; j < 4; j++) {
			func(grid, i, { 0, 0 }, j, 1);
			func(grid, i, { 0, 1 }, j, 1);
			func(grid, i, { 1, 0 }, j, 1);
			func(grid, i, { 1, 1 }, j, 1);
		}
		is_visited[i] = false;
	}

	cout << ans;

	return 0;
}