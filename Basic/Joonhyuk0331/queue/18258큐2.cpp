#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	queue<int> q;
	string str;
	int input = 0;
	int n = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) 
	{
		cin >> str;
		if (str == "push")
		{
			cin >> input;
			q.push(input);
		}
		else if (str == "pop")
		{
			if (q.size()==0) {
				cout << -1 << '\n';
			}
			else {
				int data = 0;
				data = q.front();
				q.pop();
				cout << data << '\n';
			}
		}
		else if (str == "size")
		{
			cout << q.size() << '\n';
		}
		else if (str == "empty")
		{
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "front")
		{
			if (q.size() == 0)
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (str == "back")
		{
			if (q.size() == 0)
				cout << -1 << '\n';
			else
				cout << q.back()<<'\n';
		}
	}
}
