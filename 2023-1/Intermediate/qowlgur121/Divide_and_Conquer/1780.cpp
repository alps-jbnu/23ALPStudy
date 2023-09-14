#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int result[3];	//주어진 종이 내에서 -1, 0, 1의 값을 갖는 칸의 수를 담는 배열
int map[2200][2200];	//

// 단위 종이 내 모든 칸들이 모두 같은지 아닌지 판단하는 함수
bool check(int row, int col, int num) {
	// 시작점
	int start = map[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != map[i][j])
				return false;
		}
	}
	return true;
}

// 9분할로 나눠보는 함수
void divide(int row, int col, int num) {	//행, 열, 한변의 길이

	// 지금 단위 종이 내 모든 칸들의 값이 같을 경우
	if (check(row, col, num)) {
		result[map[row][col]]++;
	}
	else {
		// 새로운 단위사이즈를 만든다.
		int size = num / 3; // 처음에 num 27이었다면 다음 단위 정사각형은 한 변의 길이가 9

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(row + size * i, col + size * j, size);	//정사각형의 시작 위치는 기존의 정사각형의 왼쪽 위 모서리의 좌표를 기준
			}
		}
	}
}


int main() {

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			int input;
			cin >> input;
			input++; // -1,0,1 을 각각 0,1,2로 표현,각 단계에서 새로운 정사각형을 만들기 위해 주어진 정사각형의 크기를 3으로 나누어야 해서		
			map[i][j] = input;
		}
	}
	divide(0, 0, N);
	cout << result[0] << '\n' << result[1] << '\n' << result[2];
}
