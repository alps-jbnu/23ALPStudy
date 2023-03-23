#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string st;
	int M;
	char cmd;
	list<char> l;
	cin >> st;
	for (auto e : st)
		l.push_back(e);
	auto it = l.end();

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 'P') {
			char char_P;
			cin >> char_P;
			l.insert(it, char_P);
		}
		else if (cmd == 'L') {
			if (it != l.begin()) it--;
		}
		else if (cmd == 'D') {
			if (it != l.end()) it++;
		}
		else {
			if (it != l.begin()) {
				it--;
				it = l.erase(it);
			}
		}
	}
	for (auto e : l)
		cout << e;
}
