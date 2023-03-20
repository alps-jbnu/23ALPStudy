#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n[1000] = {};
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{

		n[s[i]]++;

	}

	for (int i = 0; i < 26; i++)
	{
		cout << n[97 + i] << " ";

	}


}
