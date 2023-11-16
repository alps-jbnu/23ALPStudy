#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long ans = 0;
	vector<int> vP, vN;
	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		if (in == 1)
			ans += in;				// 1인 경우 묶지 않고 바로 더해야 최댓값
		else if (in > 0)				// 0은 negative와 묶어야 ans의 최댓값이 보장됨
			vP.push_back(in);
		else
			vN.push_back(in);
	}
	sort(vP.begin(), vP.end(), greater<>());
	sort(vN.begin(), vN.end());
	
	for (int i = 0; i < vP.size(); i += 2)
	{
		if ((i + 1) == vP.size())		// 홀수인 경우
		{
			ans += vP[i];
			break;
		}
		ans += vP[i] * vP[i + 1];
	}

	for (int i = 0; i < vN.size(); i += 2)
	{
		if ((i + 1) == vN.size())		// 홀수인 경우
		{
			ans += vN[i];
			break;
		}
		ans += vN[i] * vN[i + 1];
	}
	cout << ans;

	return 0;
}
