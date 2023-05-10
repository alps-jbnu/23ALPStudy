#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;


	int a[600][600] = {};

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	int cmt = 0;
	int max = 0;
	
		int cnt=0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			

			if (max <= cnt)
				max = cnt;
			cnt = 0;

			if (a[i][j] == 1)
			{		deque<int> q1;
					deque<int>q2;
					q1.push_back(i);
					q2.push_back(j);
					cmt++;

				while (1)
				{	

					if (q1.empty()==true)
							break;


					int x = q1.front();
					int y = q2.front();

					if (a[x][y] == 0)
					{
						q1.pop_front();
						q2.pop_front();
						continue;
					}
					a[x][y] = 0;



					q1.pop_front();
					q2.pop_front();

					cnt++;

					if (a[x][y + 1] == 1)
					{
						q1.push_back(x);
						q2.push_back(y + 1);

					}
					if (a[x][y - 1] == 1)
					{
						q1.push_back(x);
						q2.push_back(y - 1);

					}
					if (a[x + 1][y] == 1)
					{
						q1.push_back(x + 1);
						q2.push_back(y);

					}
					if (a[x - 1][y] == 1)
					{
						q1.push_back(x - 1);
						q2.push_back(y);
					}


				}



			}



		}
	}

	cout << cmt <<endl<< max;



}
