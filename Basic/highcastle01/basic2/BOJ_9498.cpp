#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin >> n;
	
	if(n <= 100 && n >= 90)
	{
		cout << "A";
	}
	else if(n <= 89 && n >= 80)
	{
		cout << "B";
	}
	else if(n <= 79 && n >= 70)
	{
		cout << "C";
	}
	else if(n <= 69 && n >= 60)
	{
		cout << "D";
	}
	else
	{
		cout << "F";
	}
  
  return 0;
}
