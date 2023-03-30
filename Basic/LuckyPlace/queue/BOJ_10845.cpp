#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	queue<int> Q;
	int N;
	cin >> N;
	string str;
	int a;
	while (N--)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> a;
			Q.push(a);
		}
		else if (str == "front")
		{
			if (Q.empty())
				cout << -1 << endl;
			else
				cout << Q.front() << endl;
		}
		else if (str == "back")
		{
			if (Q.empty())
				cout << -1 << endl;
			else
				cout << Q.back() << endl;
		}
		else if (str == "size")
			cout << Q.size() << endl;
		else if (str == "pop")
		{
			if (Q.empty())
				cout << -1 << endl;
			else
			{
				cout << Q.front() << endl;
				Q.pop();
			}
		}
		else if (str == "empty")
			cout << Q.empty() << endl;
	}

	return 0;
}