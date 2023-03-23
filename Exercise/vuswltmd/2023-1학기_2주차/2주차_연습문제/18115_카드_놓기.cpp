#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

int N;
vector<int> order;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		order.push_back(num);
	}

	reverse(order.begin(), order.end());
	int num = 1;

	for (int i = 0; i < N; i++) {
		if (order[i] == 1) {
			dq.push_back(num);

		}
		else if (order[i] == 2) {
			int tmp = dq.back();
			dq.pop_back();
			dq.push_back(num);
			dq.push_back(tmp);
		}
		else {
			dq.push_front(num);
		}
		num++;
	}

	for (int i = dq.size() - 1; i >= 0; i--) {
		cout << dq[i] << ' ';
	}
}
