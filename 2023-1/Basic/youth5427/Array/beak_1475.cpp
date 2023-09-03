///*
//	Day: 2023.03.15
//	참고 :
//*/
//#include <iostream>
//#include <algorithm>
//#inude <cstdlib>
//using namespace std;
//
//int main() {
//	int room = 0;
//	cin >> room;
//	int num[10] = { 0 };
//	while (room > 0) {
//		num[room % 10]++;
//		room /= 10;
//	}
//	
//	int sum = (num[6] + num[9])/2;//반절
//	if (sum % 2 == 0)sum += 1;
//	int dis = abs(num[6] - num[9]);//차이
//
//	if( sum<dis)			//5 1   반절 3 차이 4
//
//
//	int ans = *max_element(begin(num), end(num));
//	cout << ans << "\n";
//}


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