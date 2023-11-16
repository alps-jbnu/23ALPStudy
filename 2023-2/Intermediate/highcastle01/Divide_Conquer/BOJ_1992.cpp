#include<bits/stdc++.h>

using namespace std;

char board[65][65];

void sol(int n, int x, int y)
{
	int div = n/2, cur, i, j;
	int checkx, checky;
	char check;
	bool flag = false;
	
	if(n == 0)
	{
		return;
	}
	
	cout << "(";
	
	for(cur = 0; cur < 4; cur++)
	{
		if(cur == 0)
		{
			checkx = x;
			checky = y;
		}
		else if(cur == 1)
		{
			checkx = x;
			checky = y + div;
		}
		else if(cur == 2)
		{
			checkx = x + div;
			checky = y;
		}
		else if(cur == 3)
		{
			checkx = x + div;
			checky = y + div;
		}
		flag = false;
		check = board[checkx][checky];
		
		for(i = 0; i < div; i++)
		{
			for(j = 0; j < div; j++)
			{
				if(check != board[checkx + i][checky + j])
				{
					sol(div, checkx, checky);
					flag = true;
					break;
				}
			}
			if(flag)
			{
				break;
			}
		}
		if(!flag)
		{
			cout << check;
		}
	}
	cout << ")";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, i, j;
	bool flag = false;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	
	char check = board[0][0];
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(check != board[i][j])
			{
				flag = true;
				break;
			}
		}
		if(flag)
		{
			break;
		}
	}
	
	if(!flag)
	{
		cout << check;
	}
	else
	{
		sol(n, 0, 0);
	}
	
	cout << "\n";
	
	return 0;
}
