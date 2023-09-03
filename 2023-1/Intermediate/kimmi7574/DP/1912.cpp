#include <bits/stdc++.h>
using namespace std;

int n;
int max_val;
int arr[100005];
int d[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	//�ʱⰪ
	d[1] = arr[1];
	max_val = d[1];

	for (int i = 2; i <= n; i++) {
		d[i] = max(d[i - 1] + arr[i], arr[i]);
		max_val = max(max_val, d[i]);
	}

	cout << max_val;
}