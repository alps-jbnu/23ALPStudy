#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <list>
#include <tuple>
#include <set>
using namespace std;

int arr[500005];
int N, M;

int binarySearch(int& target) {
	int st = 0;
	int en = N;
	// target의 첫번째 위치 찾기
	while (st < en) {
		int mid = (st + en) / 2;
		if (arr[mid] >= target) en = mid;
		else st = mid + 1;
	}
	int a = st;

	st = 0;
	en = N;
	// target의 마지막 위치 + 1 찾기
	while (st < en) {
		int mid = (st + en) / 2;
		if (arr[mid] > target) en = mid;
		else st = mid + 1;
	}
	int b = st;

	return b - a;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int target;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	cin >> M;
	while (M--) {
		cin >> target;
		cout << binarySearch(target) << ' ';
	}

	return 0;
}
