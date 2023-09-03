#include<iostream>
#include<algorithm>

using namespace std;

int abc[3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c, i;
	
	cin >> abc[0] >> abc[1] >> abc[2];
	
	sort(abc, abc+3);
	
	for(i = 0; i < 3; i++)
	{
		cout << abc[i] << " ";
	}
	
	return 0;
}
