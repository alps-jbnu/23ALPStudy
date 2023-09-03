#include <bits/stdc++.h>
const int MAX = 100 + 1;
using namespace std;

int N, result = 0;
int x, y, d, g;
int arr[MAX][MAX];
int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
vector<int> vec;

void Solve()
{
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		int cd = (vec[i] + 1) % 4;
		y += dir[cd][0];
		x += dir[cd][1];
		arr[y][x] = 1;

		vec.push_back(cd);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> d >> g;
		vec.clear();

		arr[y][x] = 1;
		y += dir[d][0];
		x += dir[d][1];
		arr[y][x] = 1;

		vec.push_back(d);
		while (g--)
		{
			Solve();
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1) result++;
		}
	}
	cout << result;

	return 0;
}