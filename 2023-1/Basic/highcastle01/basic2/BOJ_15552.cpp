#include<iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, A, B, i;
	
	cin >> T;
	
	for(i = 0; i < T; i++)
	{
		cin >> A >> B;
		cout << A + B << "\n";
	}
	return 0;
}
