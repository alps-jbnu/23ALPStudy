#include<iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int DP[31] = { 0 };
	int n, i, j;

	//1. input
	cin >> n;

	//2. 초기값
	DP[0] = 1;
	DP[2] = 3;


	//3. DP 구하기
	for (i = 4; i <= n; i++) {
		for (j = 2; j <= i; j += 2) {
			int multi = 2;
			if (j == 2) multi = 3;
			DP[i] += DP[i - j] * multi;
		}
	}
	cout << DP[n] << endl;



    return 0;
}
