#include <iostream>
using namespace std;

const int INF = 9999999;
int N, x, y;
int map[51][51];
int score[51]; //각 노드에 대한 최대 거리, 회원 점수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = INF;
		}
	}
	for (int i = 1; i <= N; i++) {
		map[i][i] = 0;
	}

	while (1) {
		cin >> x >> y;
		if (x == -1 && y == -1) break;

		map[x][y] = map[y][x] = 1;
	}

	for (int k = 1; k <= N; k++) { //플로이드 와샬, 최단 거리 구하기
		for (int j = 1; j <= N; j++) {
			for (int i = 1; i <= N; i++) {
				if (map[i][k] + map[k][j] < map[i][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	int minimum = INF; //가장 작은 점수 찾기 위함
	
	for (int i = 1; i <= N; i++) {
		int maximum = 0; //현재 친구 0명
		for (int j = 1; j <= N; j++) {
			maximum = max(maximum, map[i][j]); //가장 먼 친구의 점수가 회원의 최대 점수가 됨
		}
		score[i] = maximum; //회원의 점수 저장
		minimum = min(minimum, score[i]); //회원 중 가장 낮은 점수를 저장함
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (score[i] == minimum) { 
			cnt++;
		}
	}
	cout << minimum << ' ' << cnt << "\n";
	for (int i = 1; i <= N; i++) {
		if (score[i] == minimum)
			cout << i << ' ';
	}

	return 0;
}
