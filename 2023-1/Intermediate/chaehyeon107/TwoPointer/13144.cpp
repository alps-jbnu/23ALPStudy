#include <bits/stdc++.h>
using namespace std;

int n, st, en;
long long cnt = 0;
int arr[100002];
bool num[100002];


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	st = 0;
	en = 0;
	num[arr[0]] = true;
	for (st = 0; st < n; st++) {
		while (en < n-1 && !num[arr[en+1]]) {
			en++;
			num[arr[en]] = true;
		}
		cnt += (en - st + 1);
		num[arr[st]] = false;
	}
	cout << cnt;
}
