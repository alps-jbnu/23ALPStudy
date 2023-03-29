#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//멀티버스 2
//좌표압축
using namespace std;

int M, N;
int universe[105][10002];
void map_compress(int a[]) {
	vector<int> universe_copy(a, a + N);//a를 복사
	sort(universe_copy.begin(), universe_copy.end()); // 정렬--크기에 따라 배열에 위치가 바뀜.
	universe_copy.erase(unique(universe_copy.begin(), universe_copy.end()), universe_copy.end()); // 중복 제거
	for (int i = 0; i < N; i++) {
		a[i] = lower_bound(universe_copy.begin(), universe_copy.end(), a[i]) - universe_copy.begin(); // lower_bound로 바뀐 위치를 찾고 바뀐 위치 배열에 넣기
	}
}
bool compare(int a[], int b[]) {
	for (int i = 0; i < N; i++) {
		if (a[i] == b[i]) continue;
		else return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> universe[i][j];
		}
		map_compress(universe[i]);
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++)
			if (compare(universe[i], universe[j])) ans++;
			else continue;
	}
	cout << ans;

}
