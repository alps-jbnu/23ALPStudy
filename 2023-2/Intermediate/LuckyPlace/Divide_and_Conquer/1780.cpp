#include <iostream>
using namespace std;

int paper[2200][2200];
int ans[3];

bool same(int row, int col, int n)
{
	for (int i = row; i < row + n; i++)
	{
		for (int j = col; j < col + n; j++)
		{
			if (paper[row][col] != paper[i][j])
				return false;
		}
	}
	return true;
}

void is_paper(int row, int col, int n)
{
	if (n == 1)				// base case
	{
		ans[paper[row][col] + 1]++;
		return;
	}
	if (same(row, col, n))
	{
		ans[paper[row][col] + 1]++;
		return;
	}
	else
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				is_paper(row + (n / 3 * i), col + (n / 3 * j), n / 3);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	is_paper(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << "\n";

	return 0;
}
