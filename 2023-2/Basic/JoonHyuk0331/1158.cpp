#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int> v;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	cout << "<";
	int it = k - 1;
	while (!v.empty()) {
		cout<<v[it];
		v.erase(v.begin() + it);
		if (v.empty()) break;//마지막 루프에서 v배열이 모두 사라지는 경우 예외처리
		it = (it + k - 1) % v.size();
		cout << ", ";
	}
	cout << ">";
}
