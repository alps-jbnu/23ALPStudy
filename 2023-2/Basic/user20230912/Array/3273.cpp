#include <iostream>

int a[1000001];

int main()
{
	int input1, input2, count = 0;
	
	std::cin >> input1;

	for (int i = 0; i < input1; i++) {
		std::cin >> input2;
		a[input2] = 1;
	}

	std::cin >> input2;

	if (input2 < 1000000) {
		for (int i = 0; i <= input2; i++) {
			if (a[i] == 1 && a[input2 - i] == 1) {
				count++;
			}
		}
	}

	if (input2 > 1000000) {
		for (int i = input2 - 1000000; i <= 1000000; i++) {
			if (a[i] == 1 && a[input2 - i] == 1) {
				count++;
			}
		}
	}

	std::cout << count / 2;
}
