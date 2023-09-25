#include <iostream>
#include <list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	list<int> L;
	list<int>::iterator it = L.begin();
	for (int i = 1; i <= n; i++) {
		L.push_back(i);
	}

	cout << '<';
	while (!L.empty()) {
		if (it == L.end()) it = L.begin();
		for (int i = 1; i < k; i++) {
			
			it++;
			if (it == L.end()) it = L.begin();
			
        }
		if (L.size() == 1) {
			cout << *it << '>';
			L.erase(it);
			break;
		}
		else {
			cout << *it << ", ";
			it = L.erase(it);
		}
	}
	
}