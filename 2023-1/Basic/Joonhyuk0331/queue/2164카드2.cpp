#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	queue<int> q;
	int data = 0;
	int n = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++)//front(위) 1 2 3 4 back(아래)
		q.push(i);

	while (q.size() != 1) 
	{
		q.pop();
		if (q.size() == 1)
			break;
		data = q.front();
		q.pop();
		q.push(data);
	}
	cout << q.front();
}
