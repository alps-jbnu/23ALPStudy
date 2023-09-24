#include <iostream>

using namespace std;

int main() {
	int A, B, C;
	int sum;
	cin >> A >> B >> C;
	sum = A * B * C;
	int arr[10] = { 0, };
	int num;

	while (sum > 0) {
		num = sum % 10; //나눈 나머지, 현재 1의 자리
		arr[num]++;
		sum /= 10; //나머지를 없앤 몫이 다음 숫자가 됨
	}
	
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}
