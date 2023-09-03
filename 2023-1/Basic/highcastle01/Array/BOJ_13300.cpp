#include<iostream>
#include<vector>
#include<string>

using namespace std;

int nlist[2][6];

int checking(int k)
{
	int i, j, cnt = 0;
	
	for(i = 0; i < 2; i++)
	{
		for(j = 1; j <= 6; j++)
		{
			if(nlist[i][j] == 0)
			{
				continue;
			}
			else
			{
				if(nlist[i][j] > k)
				{
					cnt += (nlist[i][j] + 1) / k;
				}
				else
				{
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, i, S, Y;
	
	cin >> n >> k;
	
	for(i = 0; i < n; i++)
	{
		cin >> S >> Y;
		nlist[S][Y]++;
	}
	
	cout << checking(k);
	
	return 0;
}

// 미완성
