#include <iostream>
using namespace std;

void star(int n, int row, int col)
{
	if ((row / n) % 3 == 1 && (col / n) % 3 == 1)
		cout << " ";
	else if (n / 3 == 0)
		cout << "*";
	else
		star(n / 3, row, col);
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			star(n, i, j);
		cout << "\n";
	}
	return 0;
}
