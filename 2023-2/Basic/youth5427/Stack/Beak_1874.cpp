
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	int count = 1;
	cin >> N;
	stack<int> s;
	vector<char> op;
	
	while (N--) {
		int temp = 0;
		cin >> temp;
		while (count <= temp) {
			op.push_back('+');
			s.push(count);
			count++;
		}
		if (s.top() == temp) {
			s.pop();
			op.push_back('-');
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < op.size(); i++)
		cout << op[i] << "\n";
}
