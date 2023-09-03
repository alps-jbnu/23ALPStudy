#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int yut = 0, i, y, j;
	
	for(i = 0; i < 3; i++)
	{
		yut = 0;
		for(j = 0; j < 4; j++)
		{	
			cin >> y;
			yut += y;
		}
		if(yut == 0)
		{
			cout << "D";
		}
		else if(yut == 1)
		{
			cout << "C";
		}
		else if(yut == 2)
		{
			cout << "B";
		}
		else if(yut == 3)
		{
			cout << "A";
		}
		else if(yut == 4)
		{
			cout << "E";
		}
		
		cout << "\n";
	}
	return 0;
}
