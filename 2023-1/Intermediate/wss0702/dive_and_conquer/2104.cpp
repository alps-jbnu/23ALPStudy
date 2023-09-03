#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
long A[100005];
long long array_score(int start, int end) {
	if (start > end) return -1;
	else if (start == end) return A[start]*A[start]; // 부분배열의 길이 1 ;;
	else {
		int mid = (start + end) / 2;

		long result = max(array_score(start, mid - 1), array_score(mid + 1, end)); // 왼쪽에서 얻어진 최대 영역과 오른쪽에서 얻어진 최대영역 비교해서 최대값 찾기

		//양쪽영역에서 걸린 부분배열 중 최대 점수

		long now_min_score = A[mid];
		int left = mid;
		int right = mid;
		long now_max_sum = A[mid];

		while (right - left < end - start/*left랑 right가 start랑 end가 됐을 때 break*/) {
			long p = left > start ? A[left - 1] : -1; // 왼쪽으로 확장했을 때 최소값
			long q = right < end ? A[right + 1] : -1; // 오른쪽으로 확장했을 때 최소값

			if (p > q) {
				now_max_sum += p;
				now_min_score = min(now_min_score, p);
				left--;
			}
			else {
				now_max_sum += q;
				now_min_score = min(now_min_score, q);
				right++;
			}
			result = max(result, now_max_sum * now_min_score);// 3개 영역 중 최대점수 갱신
		}

		return result;
	}
}//최대값을 구하는 함수
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cout << array_score(0, N - 1);
	return 0;
}
