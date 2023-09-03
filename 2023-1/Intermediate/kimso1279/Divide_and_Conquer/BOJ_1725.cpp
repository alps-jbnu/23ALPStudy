#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int A[1000001];
int max_size(int st, int en){
    if(st == en) return A[en];

    int mid = (st + en)/2;
	int left = mid, right = mid+1;
	int height = min(A[left], A[right]);
	int ret = height * 2, tmp;

	while (st < left || right < en) {
		if (st == left) tmp = ++right;
		else if (right == en) tmp = --left;
		else if (A[left - 1] < A[right + 1]) tmp = ++right;
		else tmp = --left;

		height = min(height, A[tmp]);
		ret = max(ret, height * (right - left + 1));
	}

	//1. 가운데에 걸치는 부분 배열, 2. 왼쪽 부분 배열 3. 오른쪽 부분 배열 중 max 값
	return max(ret, max(max_size(st, mid), max_size(mid + 1, en)));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) cin >> A[i];
    cout << max_size(1,N);
}   
