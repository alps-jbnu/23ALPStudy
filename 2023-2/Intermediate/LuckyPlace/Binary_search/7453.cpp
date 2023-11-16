	#include <iostream>
	#include <algorithm>
	#include <vector>
	using namespace std;

	int a[4001], b[4001], c[4001], d[4001];

	int main(void)
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i] >> c[i] >> d[i];

		vector<int> two;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				two.push_back(a[i] + b[j]);

		sort(two.begin(), two.end());

		long long count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				//count += binary_search(two.begin(), two.end(), -c[i] - d[j]);  겹치는 수가 있을 수 있어서 binary_search는 안된다.
				count += upper_bound(two.begin(), two.end(), -c[i] - d[j]) - lower_bound(two.begin(), two.end(), -c[i] - d[j]);
			}
		cout << count;

		return 0;
	}
