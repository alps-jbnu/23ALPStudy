#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int N, K;
ll result = 0;
vector<ll> vec, temp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	vec.resize(N);
	temp.resize(N - 1);
	
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i < N; i++)
	{
		temp[i - 1] = vec[i] - vec[i - 1];
	}
	sort(temp.begin(), temp.end());
	
	result = 0;
	for (int i = 0; i < N - K; i++)
	{
		result += temp[i];
	}
	cout << result;

	return 0;
}