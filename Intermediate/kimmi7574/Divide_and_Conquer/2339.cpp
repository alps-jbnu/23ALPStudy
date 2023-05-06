#include <bits/stdc++.h>
using namespace std;

int n;
int arr[21][21];
//1:불순물, 2:보석결정체, 0:불순물과 보석결정체가 존재X

//석판 자를 수 없는 경우
/*1. 불순물과 보석이 1개씩인 경우
  2. 불순물만 있거나, 불순물과 보석이 둘다 없는 경우
  3. 불순물 없고, 보석이 2개이상인 경우
  4. 불순물을 자르고자 하는 방향에 보석이 있는 경우
  5. 가로로 자를 때, 불순물이 가장 위 또는 가장 아래에 있는 경우
  6. 세로로 자를 때, 불순물이 가장 왼쪽 또는 가장 오른쪽에 있는 경우

  석판을 나누었을 때 ex)세로로 나눔 -> 왼쪽 석판의 경우의수 * 오른쪽 석판의 경우의수
  */

//slice가 true - 가로로 잘림, false - 세로로 잘림
int solve(int x0, int y0, int xi, int yi, bool slice) {
	int impurities = 0, jewels = 0;
	for (int y = y0; y < yi; y++) {
		for (int x = x0; x < xi; x++) {
			if (arr[y][x] == 1)	//불순물 있음
				impurities++;
			else if (arr[y][x] == 2) //보석 있음
				jewels++;
		}
	}

	if (jewels == 1 && impurities == 0)	//불순물 x, 보석o ->진행가능
		return 1;
	else if (jewels == 1 && impurities == 1)//1번경우 -> 진행불가
		return 0;
	else if (jewels == 0)	//2번 경우 -> 진행불가
		return 0;
	else if (jewels > 2 && impurities == 0)	//3번경우 ->진행불가
		return 0;

	//불순물과 보석결정체가 여러개인 경우 -> 석판을 직접 나눠보기
	int result = 0;
	for (int y = y0; y < yi; y++) {
		for (int x = x0; x < xi; x++) {
			if (arr[y][x] == 1) { //불순물일 때
				if (slice) { //이전에 가로로 잘라서 다음은 세로만 가능
					//세로로 자를 수 있는가?
					if (x != x0 && x != xi - 1) {//양끝이 아니라서 1차합격
						bool check = true;
						for (int i = y0; i < yi; i++) {
							if (arr[i][x] == 2) { //세로에 보석이 있어서 불가능
								check = false;
								break;
							}
						}

						if (check) //세로에 보석이 없어서 2차합격
							result = result + solve(x0, y0, x, yi, false) * solve(x + 1, y0, xi, yi, false);
					}
				}

				else {//이전에 세로로 잘랐기 때문에 그 다음은 가로만 가능
					//가로로 자를 수 있는가?
					if (y != y0 && y != y - 1) { //양 끝이 아니라서 1차합격
						bool check = true;
						for (int i = x0; i < xi; i++) {
							if (arr[y][i] == 2) {	//가로에 보석이 있어서 불가능
								check = false;
								break;
							}
						}

						if (check) //가로에 보석이 없어서 2차 합격
							result = result + solve(x0, y0, xi, y, true)*solve(x0, y + 1, xi, yi, true);
					}
				}
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int impurity = 0, jewel = 0;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> arr[y][x];
			if (arr[y][x] == 1)
				impurity++;
			else if (arr[y][x] == 1)
				jewel++;
		}
	}

	if (impurity == 0 && jewel == 1)
		cout << 1;
	else {
		int resultA = solve(0, 0, n, n, true);
		int resultB = solve(0, 0, n, n, false);
		if (resultA + resultB == 0)
			cout << -1;
		else
			cout << resultA + resultB;
	}

	return 0;
}