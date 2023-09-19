#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int buf[26] = { 0 };
	for (int i = 0; i < str.length(); i++) {
		buf[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << buf[i] << ' ';
	}
}