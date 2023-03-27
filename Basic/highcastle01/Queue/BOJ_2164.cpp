#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int> nlist;
	int n, i;
	
	cin >> n;
	
	for(i = 1; i <= n; i++)
	{
		nlist.push(i);
	}
	
	while(nlist.size() != 1)
	{
		nlist.pop();
		nlist.push(nlist.front());
		nlist.pop();
	}
	
	cout << nlist.front();
	
	return 0;
}
