#include<iostream>
#include<string>
using namespace std;
int N;
string board[64];
void func(int n, int x, int y) {
	
	char temp = board[x][y];

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++)
			if(board[i][j] != temp) {
				cout << "(";
				func(n / 2, x, y);
				func(n / 2, x, y + n / 2);
				func(n / 2, x + n / 2, y);
				func(n / 2, x + n / 2, y + n / 2);
				cout << ")";
				return;
		}
	}
	cout << temp;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
	
			cin >> board[i];
		
	}
	func(N, 0, 0);
}
