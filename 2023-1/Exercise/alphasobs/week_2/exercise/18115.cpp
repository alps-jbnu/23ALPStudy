#include <bits/stdc++.h>
#define lli long long int
const int MAX = 1e9 + 1;
using namespace std;

int N, temp = 1;
vector<int> vec;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num; cin >> num;
		vec.push_back(num);
	}
	reverse(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		if (vec[i] == 1) dq.push_back(temp);
		else if (vec[i] == 2)
		{
			int dq_last = dq[dq.size() - 1];
			dq.pop_back();
			dq.push_back(temp);
			dq.push_back(dq_last);
		}
		else if (vec[i] == 3) dq.push_front(temp);

		temp++;
	}

	while (!dq.empty())
	{
		cout << dq[dq.size() - 1] << " ";
		dq.pop_back();
	}

	return 0;
}