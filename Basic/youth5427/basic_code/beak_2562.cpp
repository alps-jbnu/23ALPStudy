/*
	Day: 2023.03.12
	참고 : 최대값 함수 *max_element( , )
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9] = { 0 };
	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	int max = *max_element(begin(arr), end(arr));	// 객체 주소를 리턴하기 때문에 * 사용
	cout << max << endl;

	for (int i = 0; i < 9; i++)						// 최대값 위치 검색
		if (max == arr[i]) cout << i+1 << endl;
}