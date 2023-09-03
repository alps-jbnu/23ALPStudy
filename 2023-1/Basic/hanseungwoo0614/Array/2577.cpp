#include <iostream>

int main()
{
	int a, b, c;
	int n;

	std::cin >> a >> b >> c;

	n = a * b * c;
	int d[10] {};

	while(1)
	{
		d[n % 10] = d[n % 10] + 1;      //n=2032323  3

		if (n / 10 == 0)
			break;

		n=n / 10; 
	
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << d[i] << "\n";
	}

	return 0;
}
