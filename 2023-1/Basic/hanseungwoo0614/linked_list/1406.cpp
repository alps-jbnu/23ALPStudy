#include <bits/stdc++.h>
#include <string>
#include <list>

using namespace std;

int main()
{
	list <char> l;
	string s;
	int a;

	cin >> s >> a;

	for (int i = 0; i < s.length(); i++)
	{
		l.push_back(s[i]);
	}

	list<char>::iterator it = l.end();

	string x;

	char y;
	
	for (int i = 0; i < a; i++)
	{
		cin >> x;
		if (x == "L")
		{
			if (it == l.begin())
				continue;
			else
			it--;
			

		}
		if (x == "P")
		{
			cin >> y;
			l.insert(it, y);
		}
		if (x == "D")
		{
			if (it == l.end())
				continue;
			else
			it++;
		}
		if (x == "B")
		{
			if (it == l.begin())
				continue;
			else
			it--;
			it=l.erase(it);
			
		}

	}

	for (it = l.begin(); it != l.end(); it++)
	{
		cout << *it;
	}
	return 0;
}
