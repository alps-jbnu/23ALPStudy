#include <bits/stdc++.h>
using namespace std;

int T;	//테스트케이스 수
int n;	//날의 수
int arr[1000005];	//날 별 주가나타내는 배열

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		
		int arr[1000005] = { 0, };	//날 별 주가나타내는 배열
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int max_val = -1;
		long long result = 0;
		for (int i = n - 1; i >= 0; i--) {	//역순으로 검사하여 최댓값 갱신 & 차이만큼 빼주어 result에 더함
			max_val = max(max_val, arr[i]);
			result += max_val - arr[i];
		}

		cout << result << "\n";
	}
}