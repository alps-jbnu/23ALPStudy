#include <iostream>
using namespace std;

int a[50][2];

void preorder(int cur) {
	if (cur == -1) return;
	cout << (char)(cur + 'A');
	preorder(a[cur][0]);
	preorder(a[cur][1]);
}

void inorder(int cur) {
	if (cur == -1) return;
	inorder(a[cur][0]);
	cout << (char)(cur + 'A');
	inorder(a[cur][1]);
}

void postorder(int cur) {
	if (cur == -1) return;
	postorder(a[cur][0]);
	postorder(a[cur][1]);
	cout << (char)(cur + 'A');
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;		// 알파벳 입력

		x = x - 'A';		// 문자 -> 숫자 변환

		if (y == '.') {		// 입력이 .이면 그 자리에 -1 대입
			a[x][0] = -1;
		}
		else {
			a[x][0] = y - 'A';
		}
		if (z == '.') {
			a[x][1] = -1;
		}
		else {
			a[x][1] = z - 'A';
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	return 0;
}
