#include<iostream>
#include <algorithm>
#include<cmath>
using namespace std;

int N;
int A[3001][3001]; 
int ans[3];

int solve(int x, int y, int size) {
	
    for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++){
			if (A[i][j] != A[x][y]){	
				solve(x, y, size / 3);
				solve(x + size * 1 / 3, y, size / 3);
				solve(x + size * 2 / 3, y, size / 3);
				solve(x, y + size * 1 / 3, size / 3);
				solve(x + size * 1 / 3, y + size * 1 / 3, size / 3);
				solve(x + size * 2 / 3, y + size * 1 / 3, size / 3);
				solve(x, y + size * 2 / 3, size / 3);
				solve(x + size * 1 / 3, y + size * 2 / 3, size / 3);
				solve(x + size * 2 / 3, y + size * 2 / 3, size / 3);
				return 0;
			}
		}
	ans[A[x][y] + 1]++;
	return 0;
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	solve(0, 0, N);

	for (int i = 0; i < 3; i++) cout << ans[i] << "\n";
}
