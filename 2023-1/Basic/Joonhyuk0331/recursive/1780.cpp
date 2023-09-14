#include <iostream>
using namespace std;
int arr[2188][2188];
int p1=0;
int z0=0;
int m1=0;

bool check(int size, int x, int y) {
	int cnt = arr[x][y];
	for (int i = x; i < x + size; i++){
		for (int j = y; j < y + size; j++) {
			if (cnt != arr[i][j])
				return false;
		}
	}
	return true;
}

void fun(int size,int x,int y) {
	if (check(size,x,y)==true) {
		if (arr[x][y] == 1) {
			p1++;
		}
		else if (arr[x][y] == 0) {
			z0++;
		}
		else if (arr[x][y] == -1) {
			m1++;
		}
		return;
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			fun(size / 3, x + i * size / 3, y + j * size / 3);
		}
	}
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	fun(n, 0, 0);

	cout << m1 << '\n' << z0 << '\n' << p1;
}
