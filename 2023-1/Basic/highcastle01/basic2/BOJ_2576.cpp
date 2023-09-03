#include<iostream>
#include<algorithm>

using namespace std;

vector<int> oddlist;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i, oddsum = 0, su;
	
	for(i = 0; i < 7; i++)
	{
		cin >> su;
		if(su % 2 != 0)
		{
			oddlist.push_back(su);
			oddsum += su;
		}
	}
	
	sort(oddlist.begin(), oddlist.end());
	
	if(oddlist.empty())
	{
		cout << -1;
	}
	else
	{
		cout << oddsum << "\n" << oddlist[0];
	}
	
	return 0;
}
