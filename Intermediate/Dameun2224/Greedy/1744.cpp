#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
* 입력이 3 -1 -2 -3인 경우, 6 -1 = 5가 답이 된다.
* 
* 짝수 / 짝수		4 2 0 -2 -4
* 홀수 / 짝수``	4 2 1 0 -2 -4
* 짝수 / 홀수		4 2 0 -2 -3 -4
* 홀수 / 홀수		4 2 1 0 -2 -3 -4
*/

int n, sum;
int a[55];
int e;


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());

	for (int i = 0; i < n; i++) {
		// a[i]가 0이라면 음수인 부분을 따로 처리하기 위해 종료
		if (a[i] <= 0) {	
			e = i;
			break;
		}
		if (i == n - 1) sum += a[i];
		else if (a[i] * a[i+1] >= a[i] + a[i+1]) {
			sum += a[i] * a[i + 1];
			i++;
		}
		else sum += a[i];
	}

	if (!e && a[0] > 0) e = n;
	for (int i = n - 1; i >= e; i--) {
		if (i == e) sum += a[i];
		else if (a[i] * a[i - 1] >= a[i] + a[i - 1]) {
			sum += a[i] * a[i - 1];
			i--;
		}
		else sum += a[i];
	}

	cout << sum << '\n';

	return 0;
}
