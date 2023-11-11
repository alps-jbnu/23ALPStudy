#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<tuple>
#include<memory.h>
using namespace std;
int arr[200005];
int vis[200005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int mx = 0;
	int en = 0;
	vis[arr[0]]++;
	for (int st = 0; st < n; st++) {
		while (en + 1 != n && vis[arr[en + 1]] < k) {
			en++;
			vis[arr[en]]++;
		}
		mx = max(mx, en - st + 1);
		vis[arr[st]]--;
	}

	cout << mx;
}
