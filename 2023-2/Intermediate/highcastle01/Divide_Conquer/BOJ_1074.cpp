#include<bits/stdc++.h>

using namespace std;

int r, c, ans;

void find(int size, int y, int x)
{
	if(y == r && x == c)
	{
		cout << ans;
		return;
	}
	
	if(r < y + size && r >= y && c < x + size && c >= x)
	{
		find(size / 2, y, x);
		find(size / 2, y, x + size / 2);
		find(size / 2, y + size / 2, x);
		find(size / 2, y + size / 2, x + size / 2);
	}
	else
	{
		ans += size * size;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin >> n >> r >> c;
	find((1 << n), 0, 0);
	return 0;
}
