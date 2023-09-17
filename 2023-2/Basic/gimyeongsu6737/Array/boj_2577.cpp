#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	string str = to_string(a * b * c);
	int buf[10] = {};
	for (int i = 0; i < str.length(); i++) {
		buf[(int)str[i] - 48]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << buf[i] << '\n';
	}
}