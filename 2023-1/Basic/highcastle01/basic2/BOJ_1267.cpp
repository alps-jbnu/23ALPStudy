#include<iostream>

using namespace std;

int clist[20];

int tingys(int n)
{
	int i, ycost = 0;
	
	for(i = 0; i < n; i++)
	{
		ycost += (clist[i] / 30) * 10;
		if(clist[i] % 30 >= 0)
		{
			ycost += 10;
		}
	}
	
	return ycost;
}

int tingms(int n)
{
	int i, mcost = 0;
	
	for(i = 0; i < n; i++)
	{
		mcost += (clist[i] / 60) * 15;
		{
			if(clist[i] % 60 >= 0)
			{
				mcost += 15;
			}
		}
	}
	
	return mcost;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, i, yst = 0, mst = 0;
	cin >> N;
	
	for(i = 0; i < N; i++)
	{
		cin >> clist[i];
	}
	
	if(tingys(N) > tingms(N))
	{
		cout << "M " << tingms(N);
	}
	else if(tingys(N) < tingms(N))
	{
		cout << "Y " << tingys(N);
	}
	else
	{
		cout << "Y " << "M " << tingys(N);
	}
	
	return 0;
}
