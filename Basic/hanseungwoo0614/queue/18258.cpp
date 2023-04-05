#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;

	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		string s;

		cin >> s;

		if (s == "push")
		{
			int x;
			cin >> x;

			q.push(x);
		}
		else if (s == "front")
		{
			if (q.empty() == true)
				cout << -1 << "\n";
			else
				cout<<q.front() << "\n";
		}
		else if (s == "back")
		{
			if (q.empty() == true)
				cout << -1 << "\n";
			else
				cout<<q.back() << "\n";
		}
		else if (s == "size")
		{

			cout << q.size() << "\n";
		}
		else if (s == "empty")
		{
			if (q.empty() == true)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (s == "pop")
		{
			if (q.empty() == true)
				cout << -1 << "\n";
			else
			{
				cout << q.front()<<"\n";
				q.pop();

			}
		}
			
	}







}
