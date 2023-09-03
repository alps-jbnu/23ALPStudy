#include <iostream>
#include <stack>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	stack<pair<int, int> > st; //<index, height>
	int num, height;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> height;

		while (!st.empty()) {
			if (height < st.top().second) {
				cout << st.top().first << " ";
				break;
			}
			st.pop();
		}
		if (st.empty()) {
			cout << 0 << " ";
		}
		st.push(make_pair(i + 1, height));
	}
	return 0;
}