#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//1. 주식 하나를 산다.
//2. 원하는 만큼 가지고 있는 주식을 판다
//3. 아무것도 안한다
//최대 이익(파는 날의 주가 - 산 날의 주가)
//마지막 날 부터 탐색해서 최고 주가인 날에 최고 주가보다 낮은 주가가  나오면 사고 최고 주가보다 높은 주가가 나온다 최고 주가 변경 다시 탐색 

using namespace std;
int N, T;
int price[1000005];
vector<int> pre_price;
long long ans;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> price[i];
		}
		int m = price[N - 1];
		for (int i = N - 1; i >= 0; i--) {
			if (m > price[i]) {
				ans += m - price[i];
			}
			else {
				m = max(price[i], m);
			}
		}
		cout << ans << "\n";
		ans = 0;
	}
}
