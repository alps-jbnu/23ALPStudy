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
		cnt[tmp] = 1;
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
