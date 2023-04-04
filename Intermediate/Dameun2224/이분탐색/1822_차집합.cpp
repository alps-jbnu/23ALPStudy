#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a, b;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<int> ans;
	// a의 요소를 모두 넣고 돌리기
	// b에 a의 요소가 존재하면 continue, 아니면 push
	for (int num : a) {
		if (binary_search(b.begin(), b.end(), num)) continue;
		ans.push_back(num);
	}

	cout << ans.size() << '\n';
	for (int num : ans) cout << num << ' ';

	return 0;
}
