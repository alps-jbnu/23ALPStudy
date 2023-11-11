/*
	Day: 2023.03.15
	참고 : 숫자 자리수 세기 (6,9 중복 사용)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int room = 0;
	cin >> room;
	int num[10] = { 0 };
	while (room > 0) {
		num[room % 10]++;
		room /= 10;
	}
	
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
		}
		else
			ans = max(ans, num[i]);
	}
	cout << max(ans, (num[6] + num[9]+1) / 2);
}
