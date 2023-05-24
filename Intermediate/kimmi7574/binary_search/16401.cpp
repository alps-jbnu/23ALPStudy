#include <bits/stdc++.h>
using namespace std;

int m;	//조카 수
int n;	//과자 수
int cookie = 0;	//나눠줄 수 있는 과자의 길이
vector<int> cookieLen;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cookieLen.push_back(num);
	}
	
	int start = 1;
	int end = *max_element(cookieLen.begin(), cookieLen.end());

	while (start <= end) {
		int mid = (start + end) / 2;
		int peopleCount = 0;	//나눠줄 수 있는 조카 수
		for (int i = 0; i < n; i++) {
			peopleCount += cookieLen[i] / mid;
		}
		if (peopleCount >= m) {
			start = mid + 1;
			cookie = mid;
		}
		else if (peopleCount < m) {
			end = mid - 1;
		}
	}
	cout << cookie << "\n";

	return 0;
}