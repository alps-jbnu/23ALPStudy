#include <iostream>
using namespace std;
int numSet[8];
//0 0 0 0 0 0 0 0 0
//6 ~= 9(suppose no 9)
int max_Idx(int arr[], const int& size);
int main() {
	int roomNum;
	cin >> roomNum;
	while (roomNum > 0) {
		if (roomNum % 10 == 9)
			numSet[6]++;
		//9 => 6 replacement
		numSet[int(roomNum % 10)]++;
		/*numSet[roomNum%10]++;
		Warning C6385: Reading invalid data from 'numSet':  the readable size is '32' bytes, but '40' bytes may be read*/

		roomNum /= 10;
	}
	cout << max_Idx(numSet, 8);
}
int max_Idx(int arr[], const int& size) {
	int max = arr[0];
	arr[6] = arr[6] % 2 == 0 ? arr[6] / 2 : arr[6]/2 + 1;
	//handle #6: round down(ex. arr[6]==7==2*4-1 -> arr[6]=4=arr[6]/2+1)
	for (int i = 1; i < 9; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
