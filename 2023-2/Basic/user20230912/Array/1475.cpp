#include <iostream>

int main()
{
	int input, arr[10] = {}, max;
	bool d;

	std::cin >> input;

	while (input != 0) {
		arr[input % 10]++;
		input /= 10;
	}
	max = (arr[6] + arr[9]) / 2 + (arr[6] + arr[9]) % 2;

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9)
			continue;
		if (max < arr[i])
			max = arr[i];
	}
	std::cout << max;
}
