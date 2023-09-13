#include <iostream>
#include <sstream>

using namespace std;

int main() {
	int a, b, c;
	int n;
	string st;
	int ab[10] = { 0 };
	cin >> a >> b >> c;
	n = (a * b * c);
	//cout << n;
	st = to_string(n);
	for (int i = 0;i < st.length();i++) {
		if (st[i] == '0') {
			ab[0] += 1;
		}
		else if (st[i] == '1') {
			ab[1] += 1;
		}
		else if (st[i] == '2') {
			ab[2] += 1;
		}
		else if (st[i] == '3') {
			ab[3] += 1;
		}
		else if (st[i] == '4') {
			ab[4] += 1;
		}
		else if (st[i] == '5') {
			ab[5] += 1;
		}
		else if (st[i] == '6') {
			ab[6] += 1;
		}
		else if (st[i] == '7') {
			ab[7] += 1;
		}
		else if (st[i] == '8') {
			ab[8] += 1;
		}
		else if (st[i] == '9') {
			ab[9] += 1;
		}
	}
	for (int i = 0;i < 10;i++) {
		cout << ab[i] << "\n";
	}
}
