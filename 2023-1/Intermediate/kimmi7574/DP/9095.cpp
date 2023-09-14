#include <bits/stdc++.h>
using namespace std;

int d[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, t;
	cin >> t;

	d[1] = 1; //초기값
	d[2] = 2;
	d[3] = 4;

	for (int i = 4; i < 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];	//배열에 각 방법의 수 입력
	}
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << d[n] << '\n';	//앞 for문에서 저장해놓은 방법의 수를 바로 출력
	}
}