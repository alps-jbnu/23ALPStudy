#include <iostream>
#include <string>
using namespace std;

bool color[70][70];

bool is_same_color(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (color[x][y] != color[i][j])
				return false;
	return true;
}

void recursion(int x, int y, int n)
{
	if (is_same_color(x, y, n))
	{
		cout << color[x][y];
		return;
	}
	else
	{
		int a = n / 2;
		cout << '(';
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				recursion(a * i + x, a * j + y, a);
		cout << ')';
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	string s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			color[i][j] = (int)s[j] - 48;
		}
	}
	recursion(0, 0, N);
	return 0;
}