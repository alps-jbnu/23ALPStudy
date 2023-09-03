#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	string x;
	string y;

	cin >> n;

	int m[1000];

	
	for (int w = 0; w < n; w++)
	{
		cin >> x >> y;

		int cnt = 0;

		
		if (x.size() == y.size())
		{
			for (int i = 0; i < x.size(); i++)
			{
				for (int j = 0; j < x.size(); j++)
				{
					if (x[i] == y[j])
					{
						cnt++;
						y[j] = 0; //abb aab
						break;
					}

				}

			}
			if (cnt == x.size())
				m[w]=1;
			else
				m[w]=0;

		}
		else
			m[w]=0;


	}

	for (int i = 0; i < n; i++)
	{
		if (m[i] == 1)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}


}
