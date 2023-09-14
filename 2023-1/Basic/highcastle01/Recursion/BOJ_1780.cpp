#include<bits/stdc++.h>

using namespace std;

int n, jonge[2187][2187], cnt[3];

bool check(int x, int y, int n)
{
	for(int i = x; i < x + n; i++)
	{
		for(int j = y; j < y + n; j++)
		{
			if(jonge[x][y] != jonge[i][j])
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void sol(int x, int y, int z)
{
	int i, j, n = z / 3;
	if(check(x, y, z))
	{
		cnt[jonge[x][y] + 1] += 1;
		return ;
	}
	
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			sol(x + i * n, y + j * n, n);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, j;
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> jonge[i][j];
		}
	}
	
	sol(0, 0, n);
	for(i = 0; i < 3; i++)
	{
		cout << cnt[i] << "\n";
	}
	
	return 0;
}
