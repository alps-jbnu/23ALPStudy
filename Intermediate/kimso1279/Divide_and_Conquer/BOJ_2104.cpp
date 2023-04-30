#include <iostream>
#include <algorithm>
using namespace std;

int A[1000001];

int getMax(int x, int y){
    return (x>y) ? x : y;
}
long long multi(int from, int to){
	if (from == to) return (long long)A[from] * A[from];

	int mid = (from + to) / 2;
	long long leftSum = getMax(from, mid);
	long long rightSum = getMax(mid + 1, to);

	//1+2.왼쪽, 오른쪽 부분배열의 최대값
	long long maxValue = max(leftSum, rightSum);

	int left = mid;
	int right = mid + 1;

	long long sum = A[left] + A[right];
	long long minValue = min(A[left], A[right]);

	maxValue = max(maxValue, sum * minValue);

	while (left > from || right < to)
	{
		if(right < to && (left == from || A[left - 1] < A[right + 1])){
			sum += A[++right];
			minValue = min(minValue, (long long)A[right]);
		}
		else{
			sum += A[--left];
			minValue = min(minValue, (long long)A[left]);
		}
		long long crossSum = sum * minValue;
		// 한 칸씩 이동하면서 구한 최대값과 현재최대값 비교 후 저장
		maxValue = max(maxValue, crossSum);
	}
	//1+2+3 . 세 가지 경우 중 최대값을 구하여 저장
	return maxValue;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) cin >> A[i];
    cout << multi(1,N);
}   
