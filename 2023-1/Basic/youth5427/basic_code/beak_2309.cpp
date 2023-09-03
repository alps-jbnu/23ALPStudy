/*
	Day: 2023.03.11
	참고 :
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9] = { 0 };			// 복귀한 난쟁이 9명
	int result[7] = { 0 };		// 난쟁이 7명
				
	for (int i = 0; i < 9; i++)		// 난쟁이 키 입력
		cin >> arr[i];

	for (int a = 0; a < 9; a++) {		// 2명[a,b(a보다큰)] 제외한 경우
		int sum = 0;					// 7명의 합 : sum(100)
		for (int b = a+1; b < 9; b++){
			sum = 0;

			for (int c = 0, temp = 0 ; c < 9; c++) {
				if (c != a && c != b)	result[temp++] = arr[c];
			}
			for (int i = 0; i < 7; i++) {
				sum += result[i];
			}
			if (sum == 100) break;
		}
		if (sum == 100) break;;
	}

	sort(result, result + 7);			// 오름차순 정렬
	for (int i = 0; i < 7; i++) 		// 키 입력
		cout << result[i] << endl;
}