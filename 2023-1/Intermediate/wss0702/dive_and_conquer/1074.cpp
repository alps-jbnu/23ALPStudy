//1074 Z
#include<iostream>
#include<vector>
using namespace std;
vector<int> arr[32768];
int check;
int func(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1);
	if (r < half && c < half) return func(n - 1, r, c);
	if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
	return 3 * half * half + func(n - 1, r - half, c - half);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, r, c;
	cin >> N >> r >> c;
	cout << func(N, r, c);
}
