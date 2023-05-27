#include<bits/stdc++.h>

using namespace std;

int k;
int numcase[14], check[11];

void f(int cnt, int pos)
{
	int i;
	
	if(cnt == 6)
	{
		for(i = 0; i < 6; i++)
		{
			cout << check[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(i = pos; i < k; i++)
	{
		check[cnt] = numcase[i];
		f(cnt + 1, i + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i;
	
	while(1)
	{
		cin >> k;
		
		if(k == 0)
		{
			break;
		}
		
		for(i = 0; i < k; i++)
		{
			cin >> numcase[i];
		}
		
		f(0, 0);
		cout << "\n";
	}
	
	return 0;
}
