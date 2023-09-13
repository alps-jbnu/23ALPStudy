#include <iostream>

using namespace std;

int main() {
	int a,c,d;
	int count = 0;
	cin >> a;
	int b[100];
	for (int i = 0;i < a;i++) {
		cin >> b[i];
	}
	cin >> c;
	for (int i = 0;i < a;i++) {
		if (b[i] == c) {
			count++;
		}
	}
	cout << count;
}
