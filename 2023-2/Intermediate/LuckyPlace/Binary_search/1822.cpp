#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr1[500'005];
int arr2[500'005];

bool binary_search(int target, int n)
{
	int start = 0;
	int end = n - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (arr2[mid] < target)
			start = mid + 1;
		else if (arr2[mid] > target)
			end = mid - 1;
		else
			return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr1[i];
	for (int i = 0; i < m; i++)
		cin >> arr2[i];
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + m);
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		if (!binary_search(arr1[i], m))
			v.push_back(arr1[i]);
	}
	if (!v.size())
	{
		cout << v.size();
		return 0;
	}
	else
	{
		cout << v.size() << "\n";
		for (auto e : v)
			cout << e << ' ';
	}
	return 0;
}
