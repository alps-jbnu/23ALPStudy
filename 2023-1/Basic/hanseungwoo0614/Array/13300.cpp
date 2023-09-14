#include <bits/stdc++.h>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); 
	
	int n, k;
	int x[10][10] = {};

	std::cin >> n >> k;

	int a, b;

	for (int i = 0; i < n; i++)
	{
		std::cin >> a >> b;
		x[a][b]++;
	}
	int cnt = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			cnt = cnt + x[i][j] / k;

			if (x[i][j] % k > 0)
				cnt++;
			
		}
	}
	std::cout << cnt;


return 0;

}
