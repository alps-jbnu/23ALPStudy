#include <iostream>
using namespace std;
int result[10];	//핵심: 0~9 사이 등장한 숫자 횟수
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int mult = A * B * C;
	while (mult > 0) {
		result[mult % 10]++;
		mult /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << result[i] << '\n';
}
