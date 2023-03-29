#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	list<int> L;
	for (int i = 1; i < n + 1; i++)
		L.push_back(i);

	list<int>::iterator t = L.begin();

	for (int i = 0; i < k - 1; i++)
		t++;

	cout << '<';

	while (n > 0) {
		if (n == 1) {
			cout << *t;
			break;
		}
		cout << *t << ", ";
		t = L.erase(t);
		if (t == L.end())
			t = L.begin();
		--n;
		for (int i = 0; i < k - 1; i++) {
			t++;
			if (t == L.end()) t = L.begin();
		}
	}
	cout << '>';
}
