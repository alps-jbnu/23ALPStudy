#include <bits/stdc++.h>
#include <string>
int main()
{
	std::string s;
	std::string x;

	std::cin >> s >> x;

	int cnt = 0;

	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < x.length(); j++)
		{
			if (s[i] == x[j])
			{
				cnt++;		//werwerwer   reeeer
				x[j] = 0;
				break;
			}
		}
	}

	int t = 0;

	t = s.length() + x.length() - cnt*2;

	std::cout << t;

}
