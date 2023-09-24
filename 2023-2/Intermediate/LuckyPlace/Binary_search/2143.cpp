#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
int A[1005];
int B[1005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t, n, m;
	cin >> t >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> B[i];

	int sum;
	vector<int> v1, v2;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		sum += A[i];
		v1.push_back(sum);
		for (int j = i + 1; j < n; j++)
		{
			sum += A[j];
			v1.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		sum = 0;
		sum += B[i];
		v2.push_back(sum);
		for (int j = i + 1; j < m; j++)
		{
			sum += B[j];
			v2.push_back(sum);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	ll ans = 0;
	for (auto e : v1)
		ans += upper_bound(v2.begin(), v2.end(), t - e) - lower_bound(v2.begin(), v2.end(), t - e);
	cout << ans;
	return 0;
}
