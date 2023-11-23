#include<bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int ans = 0, i;
	string sick, num;
	bool minus = false;

	cin >> sick;

	for(i = 0; i <= sick.size(); i++)
	{
		if(sick[i] == '-' || sick[i] == '+' || i == sick.size())
		{
			if(minus)
			{
				ans -= stoi(num);
				num = "";
			}
			else
			{
				ans += stoi(num);
				num = "";
			}
		}
		else
		{
			num += sick[i];
		}

		if(sick[i] == '-')
		{
			minus = true;
		}
	}

	cout << ans;

	return 0;
}
