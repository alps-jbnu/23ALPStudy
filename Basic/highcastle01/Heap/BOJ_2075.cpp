#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, tmp, i;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	cin >> n;
	
	for(i = 0; i < n * n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
		if(pq.size() > n)
		{
			pq.pop();
		}
	}
	
	cout << pq.top();
	
	return 0;
}
