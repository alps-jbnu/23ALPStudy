#include <iostream>
using namespace std;

int num[100001];
int cnt[2000001];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,tmp,x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		num[i]=tmp;
		cnt[tmp] = 1; //원소 체크(기록)을 해서 배열의 원소 a에 대해서 x-a가 배열에 있는 지 체크하는 법
	}
	cin >> x;
	int sum = 0;
	for (int i = 0; i < n; i++) {
    	// x-num[i]가 음수면 런타임에러남
		if (x-num[i]>=0 && cnt[x - num[i]] != 0 && x-num[i]>num[i]) {//i<j조건도 넣어준다.
			sum += 1;
		}
	}
	cout << sum;
	return 0;
}
