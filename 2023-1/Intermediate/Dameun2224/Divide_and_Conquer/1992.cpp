#include <iostream>
using namespace std;

int map[70][70];
int n;
string result;

void func(int m, int x, int y) {
	int key = map[x][y];
	for(int i = x; i < x + m; i++)
		for (int j = y; j < y + m; j++) {
			if (map[i][j] != key) {
				result += "(";
				func(m / 2, x, y);
				func(m / 2, x, y + m / 2);
				func(m / 2, x + m / 2, y);
				func(m / 2, x + m / 2, y + m / 2);
				result += ")";
				return;
			}
		}
	if (key == 0) result += "0";
	if (key == 1) result += "1";
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= n; j++)
			map[i][j] = str[j-1] - '0';
	}
		
	func(n, 1, 1);
	cout << result << '\n';

	return 0;
}
