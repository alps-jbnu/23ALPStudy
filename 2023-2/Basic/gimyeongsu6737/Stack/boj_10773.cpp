#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k;
	stack<int> st;
	cin >> k;
	while (k > 0) {
		k--;
		int n;
		cin >> n;
		if (n != 0) {
			st.push(n);
		}
		else {
			st.pop();
		}
    }
	int sum = 0;
	while (!st.empty()) {
		sum = sum + st.top();
		st.pop();
	}
	cout << sum;
}