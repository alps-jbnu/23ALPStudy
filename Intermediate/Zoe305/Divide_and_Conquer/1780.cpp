#include <bits/stdc++.h>
using namespace std;

int res[3];
int pap[2200][2200];
int n;

bool check(int row, int col, int num){
	int start = pap[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != pap[i][j])
				return false;
		}
	}
	return true;
}

void divide(int row, int col, int num){
	if (check(row, col, num)) res[pap[row][col]]++;
	else{
		int size = num / 3;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				divide(row + size * i, col + size * j, size);
			}
		}
	}
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
            int input;
			cin >> input;
			input++;	
			pap[i][j] = input;
		}
	}
	divide(0, 0, n);
    cout << res[0] << '\n' << res[1]<< '\n' << res[2];
}