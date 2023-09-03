#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a;
	int x=0;
	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a != 0)
		{
			s.push(a);
			
		}
		else
		{
			s.pop();
		}
	}

	while (1)
	{
		if (s.empty())
			break;
		else
		{
			x = x + s.top();
			s.pop();
		}

	}
	cout << x<<endl;


}
