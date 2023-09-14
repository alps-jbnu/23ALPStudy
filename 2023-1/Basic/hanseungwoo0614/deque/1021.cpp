#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;

	cin >> n>>m;

	deque<int> d;

	for (int i = 1; i <= n; i++)
	{
		d.push_back(i);
	}

	int a = 0;
	int num;
	
	
	
	for (int i = 1; i <= m; i++)
	{int cnt = 0;
	int cmt = 1;
		int x;
		cin >> x;
		deque<int> dq;
			dq = d;
		while (1)
		{
			
			if (x == dq.front())
				break;

			dq.pop_front();

			cnt++;
		}
		
			dq = d;
		while (1)
		{
			
			if (x == dq.back())
				break;
			
			int y;
			y=dq.back();
			dq.pop_back();

			cmt++;

		}
		num = (cnt > cmt) ? cmt : cnt;
		a = a + num;
		
		if (num == cnt)
		{
			while (1)
			{
				if (x == d.front())
				{
					d.pop_front();
					break;
				}
				d.push_back(d.front());
				d.pop_front();

				
					

			}
		}
		else
		{
			while (1)
			{
				if (x == d.back())
				{
					d.pop_back();
					break;
				}
				d.push_front(d.back());
				d.pop_back();
				

				

			}
		}
		
		
	}
	cout << a;

}
