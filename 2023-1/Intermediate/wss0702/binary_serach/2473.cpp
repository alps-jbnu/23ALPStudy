#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//용액
//abs 절댓값
using namespace std;

int N;
long long arr[5002];
long long ans[3];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	long long ans[] = { 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f };
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int idx = lower_bound(arr, arr + N, -arr[i] - arr[j]) - arr;
			//idx가 i가되면 arr[i]+- 의 경우만 살펴보게 됨 그럴때 i+1또는 i-1의 값이 j가 되면 ans3의 값을 잘못찾는 케이스가 존재
			// 따라서 idx +2 ~-2까지 살펴봐야함
			
			for (int k = -2; k <= 2; k++) {
				if (idx + k == i || idx + k == j) continue; // 위에서 말한 i와j가되는 경우
				if (idx + k < 0 || idx + k >= N) continue;
				if (abs(ans[0] + ans[1] + ans[2]) > abs(arr[i] + arr[j] + arr[idx + k])) {
					ans[0] = arr[i];
					ans[1] = arr[j];
					ans[2] = arr[idx + k];
				}
			
			}
		}
	}
	
	sort(ans, ans + 3);

	cout << ans[0] << " " << ans[1] << " " << ans[2];
}
