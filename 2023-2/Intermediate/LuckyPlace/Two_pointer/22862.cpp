#include <iostream>
using namespace std;

int S[1'000'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> S[i];
	int odd_count = 0;
	int even_count = 0;
	int maximum = 0;
	int start = 0;
	for (int end = 0; end < n; end++)
	{
		if (S[end] % 2 == 1)
			odd_count++;
		else
			even_count++;
		while (odd_count > k)
		{
			if (S[start] % 2 == 1)
				odd_count--;
			else
				even_count--;
			start++;
		}
		maximum = max(maximum, even_count);
	}
	cout << maximum;

	return 0;
}
