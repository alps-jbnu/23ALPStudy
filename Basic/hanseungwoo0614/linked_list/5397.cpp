#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	string s;

	cin >> a;
	for (int j = 0; j < a; j++)
	{
		list<char> L = {};

		auto it = L.begin();

		cin >> s;
		for (auto t:s)
		{
			if (t == '<')
			{
				if (it != L.begin())
					it--;
			}
			else if (t == '>')
			{
				if (it != L.end())
					it++;
			}
			else if (t == '-')
			{
				if (it != L.begin())
				{
					it--;
					it = L.erase(it);
					
				}
			}
			else
			{
				L.insert(it, t);
			}

		}
		for (auto t:L)
			cout << t;
		cout << endl;
	}
	return 0;
}
