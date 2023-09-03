#include <iostream>
#include <list>
using namespace std;

int main(void)
{
	list<int> L = {};
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		L.push_back(i);
	auto p = L.begin();
	cout << "<";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K - 1; j++)
		{
			if (p == L.end())
				p = L.begin();
			++p;
		}
		if (p == L.end())
			p = L.begin();
		if (i == N - 1)
			cout << *p;
		else
			cout << *p << ", ";
		p = L.erase(p);
	}
	cout << ">";
	return 0;
}