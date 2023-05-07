#include <bits/stdc++.h>
using namespace std;

int n;
int A[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	sort(A, A + n);	//로프 배열 정렬

	int max_w = 0;
	for (int i = 0; i <= n; i++) {	//i: 로프 사용 개수
		max_w = max(max_w, A[n - i] * i);
		//i개 중 가장 작은(n - i) 중량이(A[n - i]) 기준 됨.
		//기준 * i개 => 최대 중량
	}

	cout << max_w;
}