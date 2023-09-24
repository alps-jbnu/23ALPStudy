#include <iostream>
#include <list>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	list<char> L;
	for (int i = 0; i < s.length(); i++) {
		L.push_back(s[i]);
	}
	list<char>::iterator it = L.end();
	int n;
	cin >> n;
	while (n > 0) {
		n--;
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (it != L.begin()) it--;
		}
		if (cmd == 'D') {
			if (it != L.end()) it++;
		}
		if (cmd == 'B') {
			if (it != L.begin()) {
				it--;
				it = L.erase(it);
			}
		}
		if (cmd == 'P') {
			char c;
			cin >> c;
			L.insert(it, c);
		}
	}
	for (it = L.begin(); it != L.end(); it++) {
		cout << *it;
	}
}