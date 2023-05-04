#include <iostream>
using namespace std;

int map[2200][2200];
int one = 0;
int zero = 0;
int m_one = 0;
void paper(int x, int y, int size) {
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
		paper(x, y, size / 3);
		paper(x, y + size / 3, size / 3);
		paper(x, y + size / 3 + size / 3, size / 3);
		paper(x + size / 3, y, size / 3);
		paper(x + size / 3, y + size / 3, size / 3);
		paper(x + size / 3, y + size / 3 + size / 3, size / 3);
		paper(x + size / 3 + size / 3, y, size / 3);
		paper(x + size / 3 + size / 3, y + size / 3, size / 3);
		paper(x + size / 3 + size / 3, y + size / 3 + size / 3, size / 3);
	}
	else {
		if (map[x][y] == 1) {
			one++;
		}
		else if (map[x][y] == -1) {
			m_one++;
		}
		else if (map[x][y] == 0) {
			zero++;
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

	paper(0, 0, size);

	cout << m_one << endl;
	cout << zero << endl;
	cout << one << endl;
}
