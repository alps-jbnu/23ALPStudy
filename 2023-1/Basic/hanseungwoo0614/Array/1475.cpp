#include <iostream>

int main()
{
	int n;

	std::cin >> n;

	int d[10]{};

	while (1)
	{
		d[n % 10]++;
		if (n / 10 == 0)
			break;

		n = n / 10;
	}
	d[6] = (d[6] + d[9]+1) / 2;   //6669
	d[9] = d[6];
	
	int m;
	m = 0;
	for (int i = 0; i < 10; i++)
	{
		if (d[i] > m)   //126666
			m = d[i];
	}

	std::cout << m;

	return 0;
}
