#include<iostream>
#include<vector>

using namespace std;

vector<int> nlist(100);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, v, cnt = 0;
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> nlist[i];
	}
	
	cin >> v;
	
	for(i = 0; i < n; i++)
	{
		if(nlist[i] == v)
		{
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
