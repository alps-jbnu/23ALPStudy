#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k,n;
	cin >> k;
	stack<int> st;
	
	for (int i = 0; i < k; i++) {
		cin >> n;
		if (n != 0) {
			st.push(n);
		}
		else {
			st.pop();
		}
	}
	int sum = 0;
	int size = st.size();
	for (int i = 0; i < size; i++) {
		sum += st.top();
		st.pop();
	}
	cout << sum;

	return 0;
}
