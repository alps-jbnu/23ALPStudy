#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int H[100005];
int histogram(int start, int end) {
	if (start == end) return 0; // 영역 0;
	if (start + 1 == end) return H[start]; // 영역 1;

	int mid = (start + end) / 2;
	int result = max(histogram(start, mid), histogram(mid, end)); // 왼쪽에서 얻어진 최대 영역과 오른쪽에서 얻어진 최대영역 비교해서 최대값 찾기

	//양쪽영역에서 걸린 직사각형 중 최대 영역
	int w = 1;
	int h = H[mid];
	int left = mid; 
	int right = mid;
	while (right - left + 1 < end - start/*left랑 right가 start랑 end가 됐을 때 break*/) {
		int p = left > start ? min(h, H[left - 1]) : -1; // 왼쪽으로 확장했을 때
		int q = right < end - 1 ? min(h, H[right + 1]) : -1; // 오른쪽으로 확장했을 때
		if (p >= q) {
			h = p;
			left--;
		}
		else {
			h = q;
			right++;
		}
		w++; // 왼쪽이든 오른쪽이든 한칸이 확장됐기 때문에
		result = max(result, w * h);// 3개 영역 중 최대영역 갱신
	}

	return result;
}//최대값을 구하는 함수
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
	cout << histogram(0, N);
	return 0;
}
