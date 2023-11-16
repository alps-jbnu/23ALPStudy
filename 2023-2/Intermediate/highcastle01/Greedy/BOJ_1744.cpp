#include<bits/stdc++.h>

using namespace std;

vector<int> yang;
vector<int> um;

int ans = 0;

void hap(vector<int> v)
{
	while(v.size() > 1)
	{
		ans += *(v.end() - 1)* *(v.end() - 2);
		v.pop_back(); v.pop_back();
	}
	if(v.size())
	{
		ans += v[0];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if(x > 0)
		{
			if(x == 1)
			{
				ans += 1;
			}
			else
			{
				yang.push_back(x);
			}
		}
		else
		{
			um.push_back(x);
		}
	}

	sort(yang.begin(), yang.end());
	sort(um.begin(), um.end(), greater<>());

	hap(yang);
	hap(um);

	cout << ans;

	return 0;
}
