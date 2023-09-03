#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t, k, q;
	
	cin >> t;
	
	while(t--)
	{
		cin >> k;
		
		multiset<int> ms;
		
		while(k--)
		{
			char command;
			cin >> command;
			
			if(command == 'I')
			{
				cin >> q;
				ms.insert(q);
			}
			else if(command == 'D')
			{
				cin >> q;
				if(!ms.empty())
				{
					if(q == 1)
					{
						ms.erase(prev(ms.end()));
					}
					else
					{
						ms.erase(ms.begin());
					}
				}
			}
		}
		if(ms.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
		}
	}
	
	return 0;
}
