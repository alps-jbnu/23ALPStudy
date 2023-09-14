#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bucket[2][10];
bool used[2][10];
vector<int> ans;

void func(int day, int sum) {
	if (day == 4) {
		ans.push_back(sum);
		return;
	}

	//같은 바스켓으로 왕복하는 경우 2일소비, 같은 바스켓이므로 더하고 빼지는 우유 양이 같음
	//따라서 sum도 같음
	if (day + 2 <= 4) func(day + 2, sum);
		
	int k = 1; // day가 홀수면 k = 0
	if (day % 2 == 0)
	{ 
		int k = 0; // day가 홀수면 k = 1
	}

	for (int i = 0; i < 10; i++)
		if (used[k][i] == 0) {
			used[k][i] = true;

			if (k == 1) {
				//다음 함수가 홀수날
				func(day + 1, sum + bucket[k][i]);
			}
			else {
				//다음 함수가 짝수날
				func(day + 1, sum - bucket[k][i]);
			}
			used[k][i] = false;
		}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> bucket[i][j];
		}
	}

	func(0, 0);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size();
	return 0;
}
