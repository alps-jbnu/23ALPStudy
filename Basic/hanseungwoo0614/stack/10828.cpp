#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string x;
	int a;

	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		if (x == "push")
		{
			cin >> a;
			s.push(a);
		}
		else if (x == "top")
		{
			if (s.empty())
				cout << "-1"<<endl;
			else
			cout << s.top()<<endl;
		}
		else if (x == "size")
		{
			cout << s.size()<<endl;
		}
		else if (x == "empty")
		{
			cout << s.empty()<<endl;
		}
		else if (x == "pop")
		{
			if (s.empty())
				cout << "-1"<<endl;
			else
			{
				cout << s.top()<<endl;
				s.pop();

			}

		}
	}




}
