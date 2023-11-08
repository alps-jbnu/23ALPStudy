#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int T, l;
int current_x, current_y, target_x, target_y;
int arr[301][301]; //최소 이동 횟수
int visited[301][301]; //방문여부
int xfield[] = {1, 2, 2, 1, -1, -2, -1, -2};
int yfield[] = {2, 1, -1, -2, -2, -1, 2, 1};
queue<pair<int, int>> q;

void bfs(int x, int y) {
	q.push({ x, y }); //시작위치
	visited[x][y] = true;
	while (!q.empty()) { //q가 비어있지 않을 동안 bfs 수행
		//큐에서 현재 위치를 꺼내 변수에 저장
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == target_x && b == target_y) {
			cout << arr[a][b] << '\n';
			while (!q.empty()) {
				q.pop();
			}
			break;
		}
		for (int i = 0; i < 8; i++) { //다음 위치 저장
			int aa = a + xfield[i];
			int bb = b + yfield[i];
			//다음 위치가 칸 내에 위치하고, 아직 방문하지 않았다면
			if (0 <= aa && 0 <= bb && aa < l && bb < l && !visited[aa][bb]) {
				q.push({ aa, bb });
				visited[aa][bb] = true;
				arr[aa][bb] = arr[a][b] + 1;
			}
		}
	}
}

//main 함수보다 앞에 선언되어야 함
void reset() {
	while (!q.empty()) q.pop();
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			visited[i][j] = 0;
			arr[i][j] = 0;
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> l;
		cin >> current_x >> current_y;
		cin >> target_x >> target_y;

		bfs(current_x, current_y);
		reset();
	}
}
