#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int sum = 0;
	int multi = 1;
	for (int i = 0; i < N && arr[i] <= 0; i++) {	//요소가 음수인 동안
		if (multi < 0) {		//묶는 수에 음수가 있으면
			multi *= arr[i];	//곱해서 양수로 만들고
			sum += multi;		//더해줌
			multi = 1;			//다시 1로
		}
		else if (multi == 1) {	//묶는수에 아직 아무것도 없으면
			multi *= arr[i];	//묶어놓기
		}
	}
	if (multi != 1) {			//양수로 넘어가기 전 남은 값 처리
		sum += multi;
		multi = 1;
	}

	for (int i = N - 1; i >= 0 && arr[i] > 0; i--) {
		if (arr[i] == 1) {
			sum += 1;
		}
		else if (multi > 1) {
			multi *= arr[i];
			sum += multi;
			multi = 1;
		}
		else if (multi == 1) {
			multi *= arr[i];
		}
	}

	if (multi != 1) {
		sum += multi;
	}

	cout << sum;
}
