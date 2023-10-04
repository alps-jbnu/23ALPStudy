/*

	참고 : 잘 모르겠는디...

*/

#include <iostream>
#include <stack>
#include <string>
#define X first
#define Y second
using namespace std;
stack<pair<int, int>> tower;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	cin >> N;

	tower.push({ 100000001,0 });
	for (int i = 1; i <= N; i++) {
		int height = 0; cin >> height;
		while (tower.top().X < height) {
			tower.pop();
		}
		cout << tower.top().Y << " ";
		tower.push({ height, i });

	}
}

