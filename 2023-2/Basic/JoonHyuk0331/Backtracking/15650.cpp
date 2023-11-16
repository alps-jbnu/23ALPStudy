#include <bits/stdc++.h>
using namespace std;

int n, maxn;//1부터 n까지 자연수 중에서 중복 없이 m개를 고른 수열
int printer[10];
bool used[10];

bool is_ascneding(int arr[], int size) {
	for (int i = 0; i < size-1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}

void func(int k) {
	if (k == maxn) {//base case
		if (is_ascneding(printer, maxn)) {
			for (int i = 0; i < maxn; i++)
				cout << printer[i] << ' ';//arr에 기록해둔 수 출력
			cout << '\n';
		}
		return;
	}

	//핵심 부분
	for (int i = 1; i <= n; i++) {//1부터 n까지 돌면서 확인
		if (used[i] == false) {//used[i]가 사용되지 않았다면
			printer[k] = i;//출력부를 i 갱신하고
			used[i] = 1;//i는 사용되었다고 명시한다
			func(k + 1);
			used[i] = 0;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> maxn;
	func(0);
}
