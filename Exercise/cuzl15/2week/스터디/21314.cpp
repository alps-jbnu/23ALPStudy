#include<bits/stdc++.h>
using namespace std;

string s;
stack<char> st;
string mx="";
string mn="";


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i <s.length();) {
		while (i < s.size()) {
			if (s[i] == 'M') {
				int a = i;
				while (a < s.size()) {
					if (s[a] == 'M')	++a;
					else break;
				}

				if (a == s.size()) {
					for (int j = 0; j < a - i; j++) {
						mx += '1';
					}
				}
				else {
					mx += '5';
					for (int j = 0; j < a - i; j++) {
						mx += '0';
					}
				}
				i = a+1;
			}
			else {
				mx += '5';
				++i;
			}
		}
	}
	cout << mx;
	cout << '\n';
	for (int i = 0; i < s.length();) {
		while (i < s.size()) {
			if (s[i] == 'M') {
				int a = i;
				while(a < s.size()) {
					if (s[a] == 'M') ++a;
					else break;
				}
				mn += '1';
				a--;
				for (int j = 0; j < a - i; j++) {
					mn += '0';	
				}
				i = a+1;
			}
			else {
				mn += '5';
				++i;
			}
		}
	}
	cout << mn;
 }