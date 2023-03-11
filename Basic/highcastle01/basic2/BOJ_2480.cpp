#include<iostream>
#include<algorithm>

using namespace std;

int noon[3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i;
	
	for(i = 0; i < 3; i++)
	{
		cin >> noon[i];
	}
	
	sort(noon, noon + 3);
	
	if(noon[0] == noon[2])
	{
		cout << 10000 + noon[0] * 1000;
	}
	else if(noon[0] == noon[1])
	{
		cout << 1000 + noon[0] * 100;
	}
	else if(noon[1] == noon[2])
	{
		cout << 1000 + noon[1] * 100;
	}
	else
	{
		cout << noon[2] * 100;
	}
	return 0;
}
