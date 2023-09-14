#include <iostream>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int dx[10] = {9999, 1, 1, 1, 0, 0, 0, -1, -1, -1}; //상하
int dy[10] = {9999,-1, 0, 1,-1, 0, 1, -1, 0, 1}; //좌우

string order;
char board[105][105];
int R, C;

pair<int, int> JS; //종수 위치
int _time = 0;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'I') {
				JS.X = i;
				JS.Y = j;
			}
		}
	}

	cin >> order;
	
	for (int i = 0; i < (int)order.size(); i++) {
		////////////////////////////
		//cout << '\n';
		//cout << "time: " << _time << '\n';
		//for (int i = 0; i < R; i++) {
		//	for (int j = 0; j < C; j++) {
		//		cout << board[i][j];
		//	}
		//	cout << endl;
		//}
		//cout << '\n';
		////////////////////////////

		int R_vis[105][105]; // 미친 아두이노의 이동경로, (두개의 아두이노가 겹치는 지 판단할 것임)
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] == 'R') {
					R_vis[i][j] = 1;
				}
				else {
					R_vis[i][j] = 0;
				}
			}
		}

		board[JS.X][JS.Y] = '.'; //움직일 것이므로 .으로 변경

		int JS_Moving_to_X = JS.X + dx[order[i] - '0']; // X축으로 어느방향으로 이동할지 저장
		int JS_Moving_to_Y = JS.Y + dy[order[i] - '0']; // Y축으로 어느방향으로 이동할지 저장

		_time++;
		if (board[JS_Moving_to_X][JS_Moving_to_Y] == 'R') {
			cout << "kraj " << _time;
			return 0;
		}

		board[JS_Moving_to_X][JS_Moving_to_Y] = 'I'; // 이동확정

		JS.X = JS_Moving_to_X;
		JS.Y = JS_Moving_to_Y; // 종수의 위치를 새로 저장

		vector<pair<int, int>> vec;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] == 'R') {
					vec.push_back({ i, j });
				}
			}
		}

		for (auto a : vec) {
			int i = a.X;
			int j = a.Y;

			int min = 2100000000;

			int R_Moving_to_X;
			int R_Moving_to_Y;

			for (int dir = 1; dir < 10; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (abs(JS.X - nx) + abs(JS.Y - ny) <= min) {
					min = abs(JS.X - nx) + abs(JS.Y - ny);
					R_Moving_to_X = nx;
					R_Moving_to_Y = ny;
				}
			}

			if (board[R_Moving_to_X][R_Moving_to_Y] == 'I') {
				//이동했는데 종수가 있으면 끝내기
				cout << "kraj " << _time;
				return 0;
			}

			board[i][j] = '.';
			R_vis[i][j]--;
			board[R_Moving_to_X][R_Moving_to_Y] = 'R';
			R_vis[R_Moving_to_X][R_Moving_to_Y]++;
		}

		//cout << "R_vis: " << '\n';
		//for (int i = 0; i < R; i++) {
		//	for (int j = 0; j < C; j++) {
		//		if (R_vis[i][j] == 0) {
		//			cout << '.';
		//		}
		//		else if (R_vis[i][j] < 0) {
		//			cout << '_';
		//		}
		//		else {
		//			cout << R_vis[i][j];
		//		}
		//	}
		//	cout << '\n';
		//}
		//cout << '\n';

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] == 'I') continue;
				if (R_vis[i][j] == 1) {
					board[i][j] = 'R';
				}
				else {
					board[i][j] = '.';
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}


