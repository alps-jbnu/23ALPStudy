#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;
int arr[1000002];
deque<int> d;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (arr[n -i] == 1) {
			d.push_front(i);
		}
		else if (arr[n-i] == 2) { 
			auto s = d.begin();
			if (s == d.end()) {
				d.push_back(i);
				continue;
			}
			++s; 
			int a = d.front();
			d.pop_front();
			d.push_front(i);
			d.push_front(a);
		}
		else if (arr[n-i] == 3) {
			d.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << d[i] << ' ';
	}
 }