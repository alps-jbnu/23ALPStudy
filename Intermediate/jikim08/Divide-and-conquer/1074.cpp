#include <iostream>
#include <cmath>
using namespace std;

int r, c;
int answer = 0;
void visiting(int x, int y, int size) {
	if (x == r && y == c) {
		cout << answer;
		return;
	}

	else if (r < x + size && c < y + size && r >= x && c >= y) {
		visiting(x, y, size / 2);
		visiting(x, y + size / 2, size / 2);
		visiting(x + size / 2, y, size / 2);
		visiting(x + size / 2, y + size / 2, size / 2);
	}
	else {
		answer += size * size;
	}

}
int main() {
	int size;
	
	cin >> size >> r >> c;
	visiting(0, 0, pow(2, size));
}
