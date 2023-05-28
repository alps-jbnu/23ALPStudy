#include<bits/stdc++.h>

using namespace std;

int Level[100002];
set<int> bylevel[102];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, l, p, x, i, j;
	string op;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> p >> l;
		Level[p] = l;
		bylevel[l].insert(p);
	}
	
	cin >> m;
	
	while(m--)
	{
		cin >> op;
		if(op == "recommend")
		{
			cin >> x;
			if(x == 1)
			{
				for(i = 100; i >= 0; i--)
				{
					if(bylevel[i].empty())
					{
						continue;
					}
					cout << *(prev(bylevel[i].end())) << "\n";
					break;
				}
			}
			else if(x == -1)
			{
				for(i = 0; i < 101; i++)
				{
					if(bylevel[i].empty())
					{
						continue;
					}
					cout << *bylevel[i].begin() << "\n";
					break;
				}
			}
		}
		else if(op == "add")
		{
			cin >> p >> l;
			Level[p] = l;
			bylevel[l].insert(p);
		}
		else if(op == "solved")
		{
			cin >> p;
			bylevel[Level[p]].erase(p);
		}
	}
	
	return 0;
}
