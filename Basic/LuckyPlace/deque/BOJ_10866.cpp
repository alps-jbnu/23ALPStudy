#include <iostream>
#include <deque>
#include <string>
using namespace std;


int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	deque<int> D;
	int N;
	cin >> N;
	while (N--)
	{
		string str;
		cin >> str;
		if (str == "push_front")
		{
			int a;
			cin >> a;
			D.push_front(a);
		}
		else if (str == "push_back")
		{
			int a;
			cin >> a;
			D.push_back(a);
		}
		else if (str == "pop_front")
		{
			if (D.empty())
				cout << -1 << '\n';
			else
			{
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (D.empty())
				cout << -1 << endl;
			else
			{
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		else if (str == "size")
			cout << D.size() << '\n';
		else if (str == "empty")
			cout << D.empty() << '\n';
		else if (str == "front")
		{
			if (D.empty())
				cout << -1 << '\n';
			else
				cout << D.front() << '\n';
		}
		else
		{
			if (D.empty())
				cout << -1 << '\n';
			else
				cout << D.back() << '\n';
		}
	}
	return 0;
}