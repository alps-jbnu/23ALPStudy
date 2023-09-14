#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	string str;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		list<char> L = {};
		cin >> str;
		/*for (int j = 0; j < str.size(); j++)
			L.push_back(str[j]);*/
		list<char>::iterator t = L.begin();										
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '<')
			{
				if (t != L.begin())
					--t;
			}
			else if (str[j] == '>')
			{
				if (t != L.end())
					++t;
			}
			else if (str[j] == '-')
			{
				if (t != L.begin())
				{
					--t;
					t = L.erase(t);
				}
			}
			else
				L.insert(t, str[j]);
		}
		for (auto e : L)
			cout << e;
		cout << endl;
	}
	return 0;
}