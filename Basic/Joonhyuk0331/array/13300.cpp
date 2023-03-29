#include <iostream>
#include <cmath>
using namespace std;
 
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int N, K, r, c, result = 0;
	int arr[2][6] = {};
	cin >> N >> K;
 
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		arr[r][c - 1]++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 6; j++) {
			result += ceil((double)arr[i][j] / K);
		}
	}
	cout << result;
 
	return 0;
}
