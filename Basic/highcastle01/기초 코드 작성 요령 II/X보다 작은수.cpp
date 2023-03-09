#include<iostream>
#include<vector>

using namespace std;

vector<int> nlist;

int main(void)
{
	int n, x, i, a;
	
	cin >> n >> x;
	
	for(i = 0; i < n; i++)
	{
		cin >> a;
		nlist.push_back(a);
	}
	
	for(i = 0; i < n; i++)
	{
		if(nlist[i] < x)
		{
			cout << nlist[i] << " ";
		}
	}
	return 0;
}
