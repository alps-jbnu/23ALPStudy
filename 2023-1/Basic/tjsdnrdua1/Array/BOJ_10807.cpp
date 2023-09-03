#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int arr[100];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	int v;
	std::cin >> v;
	int m=0;			//how many v's are in arr[n]?
	for (int j = 0; j < n; j++) {
		if (v == arr[j]) m++;
	}
	std::cout << m;

}
