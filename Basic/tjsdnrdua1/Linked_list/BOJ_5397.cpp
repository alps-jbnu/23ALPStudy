#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int tc;
	string trace;
	cin >> tc;
	while (tc--) {
		list<char> pw;	
		auto it = pw.begin();
		//pw, it ->loop 안에 넣어줘야 ok
		cin >> trace;
		for(auto e:trace) {
			if (e == '<') {
				if (it != pw.begin())
					it--;
			}
			else if (e == '>') {
				if (it != pw.end())
					it++;
			}
			else if (e == '-') {
				if (it != pw.begin()) {
					it--;
					it = pw.erase(it);
				}
			}
			else
				pw.insert(it, e);
		}
		for (auto e : pw)
			cout << e;
		cout << '\n';
	}
}
