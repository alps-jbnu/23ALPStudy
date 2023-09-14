#include <bits/stdc++.h>

int map[51][51] = {};

void bfs(int b, int a)
{
	std::queue <std::pair<int,int>> q1;
	
	q1.push(std::make_pair( a,b ));
	
	int x, y;
	while (1)
	{
		if (q1.size() == 0)
			break;
		x=q1.front().first;
		y = q1.front().second;
		if (map[x][y] == 0)
		{
			q1.pop();
			continue;

		}
		map[x][y] = 0;
		
		q1.pop();
		

		if (map[x][y + 1] == 1)
		{
			q1.push(std::make_pair(x, y+1));
			

		}
		if (map[x][y - 1] == 1)
		{
			q1.push(std::make_pair(x, y-1));

		}
		if (map[x + 1][y] == 1)
		{
			q1.push(std::make_pair(x+1, y));

		}
		if (map[x - 1][y] == 1)
		{
			q1.push(std::make_pair(x-1, y));
		}

		

	}
}

int main()
{	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int T;
	std::cin >> T;
	

	for (int i = 0; i < T; i++)
	{
		int x, y, k, cnt;
		cnt = 0;

		std::cin >> x >> y >> k;

		for (int j = 0; j < k; j++)
		{
			int n, m;
			std::cin >> n >> m;
			map[m][n] = 1;  //n=0 m=2
		}

		for (int j = 0; j < y; j++)
		{
			for (int p = 0; p < x; p++)
			{
				if (map[j][p] == 1)
				{
					bfs(p, j);
					cnt++;
				}
				
			}
		}

		std::cout << cnt<<std::endl;

	}

	return 0;

}
