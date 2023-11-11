#include <iostream>
using namespace std;

pair<int, int> fib[45];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	fib[0].first = 1;
	fib[0].second = 0;
	fib[1].first = 0;
	fib[1].second = 1;
	for (int i = 2; i <= 40; i++)
	{
		fib[i].first = fib[i - 1].first + fib[i - 2].first;
		fib[i].second = fib[i - 1].second + fib[i - 2].second;
	}
	while (n--)
	{
		int in;
		cin >> in;
		cout << fib[in].first << ' ' << fib[in].second << "\n";
	}

	return 0;
}
