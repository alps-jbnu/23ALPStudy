#include <iostream>
using namespace std;

char map[2200][2200];
string result;
void quad(int x, int y, int size) {
	bool same = true;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] != map[x][y]) {
				same = false;
				break;
			}
			if (!same)
				break;
		}
	}

	if (!same) {
		result += "(";
		quad(x, y, size / 2);
		quad(x, y + size / 2, size / 2);
		quad(x + size / 2, y, size / 2);
		quad(x + size / 2, y + size / 2, size / 2);
		result += ")";
	}
	else {
		if (map[x][y] == '1') {
			result += "1";
		}
		else if (map[x][y] == '0') {
			result += "0";
		}

	}

}

int main() {
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> map[i][j];
		}
	}
	quad(0, 0, size);
	cout << result;
}
