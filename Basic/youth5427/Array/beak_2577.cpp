/*
	Day: 2023.03.15
	참고 : 
*/
#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int result = a * b * c;
	int num[10] = { 0 };
	while (result > 0) {
		num[result % 10]++;
		result = result / 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << num[i] << "\n";
	}
}
