/*
	Day: 2023.03.11
	참고 :
*/
#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	for (int i = 0; i < 3; i++) {
		int count = 0;
		cin >> a >> b >> c >> d;
		if (a == 1)	count++;	if (b == 1)count++;
		if (c == 1)count++;		if (d == 1)count++;

		if (count == 1) cout << "C" << endl;
		else if (count == 2) cout << "B" << endl;
		else if (count == 3) cout << "A" << endl;
		else if (count == 4) cout << "E" << endl;
		else if (count == 0) cout << "D" << endl;
	}
}
