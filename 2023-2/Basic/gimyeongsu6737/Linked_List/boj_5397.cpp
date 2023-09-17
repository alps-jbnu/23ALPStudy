#include<iostream>
#include<list>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n > 0) {
	    n--;
        list<char> L = {};
	
		string str;
		
		
		list<char>::iterator it = L.begin();
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (it != L.begin()) {
					it--;
				}
			}
			else if (str[i] == '>' ) {
				if (it != L.end()) {
					it++;
				}
			}
			else if (str[i] == '-') {
				if (it != L.begin()) {
					it--;
					it = L.erase(it);
				}
			}
			else {
				L.insert(it, str[i]);
				//it++;
			}
		}
		for (it = L.begin(); it != L.end(); it++) {
			cout << *it;
		}
		cout << '\n';

	}
}