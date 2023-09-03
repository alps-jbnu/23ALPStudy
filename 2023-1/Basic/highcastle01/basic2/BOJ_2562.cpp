#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i = 1, n, max = 0, maxi = 1;
	while(i < 10)
	{
		cin >> n;
		if(max < n)
		{
			max = n;
			maxi = i;
		}
		i++;
	}
	
	cout << max << "\n" << maxi;
	
	return 0;
}
