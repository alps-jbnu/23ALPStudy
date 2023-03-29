#include<bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
	stack<int> klist;
	int k, x, i, sum = 0;
	
	cin >> k;
	
	for(i = 0; i < k; i++)
	{
		cin >> x;
		if(x == 0)
		{
			klist.pop();
		}
		else
		{
			klist.push(x);
		}
	}
	
	for(i = klist.size(); i > 0; i--)
	{
		sum += klist.top();
		klist.pop();
	}
	
	cout << sum;
	
	return 0;
}
