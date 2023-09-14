#include<bits/stdc++.h>

using namespace std;

int jonge[128][128];
int cnt[2];
int n;

bool check(int x, int y, int n)
{
	int i, j;
	
	for(i = x; i < x + n; i++)
	{
		for(j = y; j < y + n; j++)
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
	int i, j, n = z / 2;
	
	if(check(x, y, z))
	{
		cnt[jonge[x][y]] += 1;
		return;
	}
	
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
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
	for(i = 0; i < 2; i++)
	{
		cout << cnt[i] << "\n";
	}
	
	return 0;
}
