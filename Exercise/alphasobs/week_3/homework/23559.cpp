#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int, int>
using namespace std;

int N, X, result = 0;
vector<pii> vec;

bool compare(pii p1, pii p2)
{
	int a = abs(p1.first - p1.second);
	int b = abs(p2.first - p2.second);

	if (a == b) return p1.second > p2.second;
	return a > b;
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> X;
	for (int i = 0; i < N; i++)
	{
		int x, y; cin >> x >> y;
		vec.push_back({ x, y });

		result += y;
	}
	sort(vec.begin(), vec.end(), compare);

	int temp = N * 1000;
	X = X - temp;

	for (int i = 0; i < N; i++)
	{
		if (X <= 0) break;

		if (vec[i].first > vec[i].second && X >= 4000)
		{
			result += vec[i].first - vec[i].second;
			X -= 4000;
		}
	}
	cout << result;

	return 0;
}