#include<iostream>
#include<algorithm>

using namespace std;

int daepyo[5];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, su, sum = 0, avg;
	
	for(i = 0; i < 5; i++)
	{
		cin >> daepyo[i];
		sum += daepyo[i];
	}
	
	avg = sum / 5;
	
	sort(daepyo, daepyo + 5);
	
	cout << avg << "\n" << daepyo[2];
	
	return 0;
}
