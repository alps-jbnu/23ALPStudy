#include<iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;

#define X first
#define Y second

int arr[501][501] = {};
int dp[501][501] = {};
bool visited[501][501] = { 0 };
int m, n;
int y_ar[4] = { 1, 0, -1, 0 };
int x_ar[4] = { 0, 1, 0, -1 };

int dfs(int cy, int cx) {


	if (cy == m && cx == n) {
		//dp[cy][cx] = 1;
		return 1; //종점이라면 1을 반환합니다. 
	}
	if (visited[cy][cx]) //이미 방문한 곳이라면 해당 dp값을 전달해준다.
		return dp[cy][cx];
	visited[cy][cx] = 1;
	for (int i = 0; i < 4; i++) {
		int next_y = cy + y_ar[i];
		int next_x = cx + x_ar[i];

		if (next_y > 0 && next_y <= m && next_x > 0 && next_x <= n)
			if (arr[cy][cx] > arr[next_y][next_x])
				dp[cy][cx] += dfs(next_y, next_x);

	}
	return dp[cy][cx];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	cout << dfs(1, 1) << '\n';

	return 0;
}
