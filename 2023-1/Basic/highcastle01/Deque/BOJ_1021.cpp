#include<bits/stdc++.h>

using namespace std;

deque<int> nque;
int nlist[50];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, i, check, j, index, cnt = 0;
	
	cin >> n >> m;
	
	for(i = 1; i <= n; i++)
	{
		nque.push_back(i);
	}
	
	for(i = 0; i < m; i++)
	{
		cin >> check;
		for(j = 0; j < n; j++)
		{
			if(nque[j] == check)
			{
				index = j;
				break;
			}
		}
		if(index < nque.size() - index)
		{
			while(1)
			{
				if(nque.front() == check)
				{
					nque.pop_front();
					break;
				}
				cnt++;
				nque.push_back(nque.front());
				nque.pop_front();
			}
		}
		else
		{
			while(1)
			{
				if(nque.front() == check)
				{
					nque.pop_front();
					break;
				}
				cnt++;
				nque.push_front(nque.back());
				nque.pop_back();
			}
		}
	}
	cout << cnt;
	return 0;
}
