#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int N;
ll result = 0;
vector<int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	vec.resize(N);

	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	int temp = 0;
	for (auto it : vec)
	{
		if (it <= temp) continue;
		temp++;

		if (temp < it) result += it - temp;
	}
	cout << result;

	return 0;
}