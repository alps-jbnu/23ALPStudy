	#include <iostream>
	#include <queue>
	int map[103][103][103];
	std::queue <int> q2;
	std::queue <std::pair<int,int>> q1;

		int cnt = -1;

	void bfs()
	{
		int x, y, z;
		int cmt = 0;
		while (1) 
		{
			int s = q1.size();

			if (q1.size() == 0)
				break;
			cmt = 0;

			for (int i = 0; i < s; i++)
			{
				
				x = q1.front().first;
				y = q1.front().second;
				z = q2.front();

				if (map[z][x][y] == 0)
				{
					
					q2.pop();
					q1.pop();
					continue;

				}
				cmt++;

				map[z][x][y] = 0;

				q1.pop();
				q2.pop();


				if (map[z][x][y + 1] == 2)
				{
					q1.push(std::make_pair(x, y + 1));
					q2.push(z);

				}
				if (map[z][x][y - 1] == 2)
				{
					q1.push(std::make_pair(x, y - 1));
					q2.push(z);
				}
				if (map[z][x + 1][y] == 2)
				{
					q1.push(std::make_pair(x + 1, y));
					q2.push(z);
				}
				if (map[z][x - 1][y] == 2)
				{
					q1.push(std::make_pair(x - 1, y));
					q2.push(z);
				}
				if (map[z + 1][x][y] == 2)
				{
					q1.push(std::make_pair(x, y));
					q2.push(z + 1);
				}
				if (map[z - 1][x][y] == 2)
				{
					q1.push(std::make_pair(x, y));
					q2.push(z - 1);
				}

			}
			if (cmt == 0)
				break;
			cnt++;

		}
			
	}


	int main()
	{	
		int m, n;
		int h;

		std::cin >> m >> n >> h;

		

		for (int p = 1; p <= h; p++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					std::cin >> map[p][i][j];

					if (map[p][i][j] == 0)
					{
						map[p][i][j] = 2;
					}
					if (map[p][i][j] == 1)
					{
						q2.push(p);
						q1.push(std::make_pair(i, j));
					}

				}
			}

		}

		bfs();

		int count = 0;

		for (int p = 1; p <= h; p++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (map[p][i][j] == 2)
						count++;

				}

			}
		}

		if (count != 0)
			std::cout << "-1";
		else
			std::cout << cnt;

		return 0;

	}
