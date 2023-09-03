#include <iostream>
#include <queue>
char map[101][101];
char m[101][101];

void bfs(int a, int b)
{
	std::queue <std::pair<int,int>> q1;
	
	q1.push(std::make_pair( a,b ));
	char c = map[a][b];
	int x, y;
	while (1)
	{
		if (q1.size() == 0)
			break;
		x=q1.front().first;
		y = q1.front().second;
		if (map[x][y] == '0')
		{
			q1.pop();
			continue;

		}
		
		map[x][y] = '0';
		
		q1.pop();
		


		if (map[x][y + 1] == c)
		{
			q1.push(std::make_pair(x, y+1));
			

		}
		if (map[x][y - 1] == c)
		{
			q1.push(std::make_pair(x, y-1));

		}
		if (map[x + 1][y] ==c)
		{
			q1.push(std::make_pair(x+1, y));

		}
		if (map[x - 1][y] == c)
		{
			q1.push(std::make_pair(x-1, y));
		}

		

	}
}

void bfsn(int a, int b)
{
	std::queue <std::pair<int, int>> q1;

	q1.push(std::make_pair(a, b));
	char c = m[a][b];
	int x, y;
	while (1)
	{
		if (q1.size() == 0)
			break;
		x = q1.front().first;
		y = q1.front().second;
		if (m[x][y] == '0')
		{
			q1.pop();
			continue;

		}

		m[x][y] = '0';

		q1.pop();



		if (m[x][y + 1] == c)
		{
			q1.push(std::make_pair(x, y + 1));


		}
		if (m[x][y - 1] == c)
		{
			q1.push(std::make_pair(x, y - 1));

		}
		if (m[x + 1][y] == c)
		{
			q1.push(std::make_pair(x + 1, y));

		}
		if (m[x - 1][y] == c)
		{
			q1.push(std::make_pair(x - 1, y));
		}



	}
}


int main()
{	
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	

	int n;
	int cnt = 0;
	int cmt = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> map[i][j];
			m[i][j] = map[i][j];

			if (m[i][j] == 'R')
				m[i][j] = 'G';

		}
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{


			if (map[i][j] == 'R' || map[i][j] == 'G' || map[i][j] == 'B')
			{
				bfs(i, j);
				cnt++;
			}
		}
	}

	


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (m[i][j] == 'G' || m[i][j] == 'B')
			{
				bfsn(i, j);
				cmt++;
			}
		}
	}

	std::cout << cnt << " " << cmt;

}
