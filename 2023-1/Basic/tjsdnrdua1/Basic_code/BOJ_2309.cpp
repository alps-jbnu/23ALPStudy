#include<iostream>
using namespace std;
int num[9], res[7];
void Sort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[i]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)cin >> num[i];
	for (int a = 0; a < 8; a++) {
		int tot = 0;	//declaration of total height except 2 dwarfs
		for (int b = a + 1; b < 9; b++) {
			tot = 0;
			for (int c = 0, j = 0; c < 9; c++) {
				//for(int c=0, j=0; c<9; c++, j++) ... error
				//store 7 dwarfs' height in array res[7]
				if (c != a && c != b) res[j++] = num[c];
			}
			for (int k = 0; k < 7; k++) tot += res[k];
			if (tot == 100) break;
		}
		if (tot == 100) break;
	}
	Sort(res, 7);
	for (int l = 0; l < 7; l++) cout << res[l] << '\n';
}
