#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int, int>> towers;
	
	int i, n, h;
	
	cin >> n;
	
	for(i = 0; i < n; i++)
	{
		cin >> h;
		while(!towers.empty())
		{
			if(towers.top().Y > h)
			{
				cout << towers.top().X << " ";
				break;
			}
			towers.pop();
		}
		if(towers.empty())
		{
			cout << "0 ";
		}
		towers.push({i + 1, h});
	}
	
	return 0;
}
//다시 풀기
