#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> S;
	int K;
	cin >> K;
	int num;
	int stack_size;
	int sum = 0;


	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num == 0) {
			S.pop();
		}
		else {
			S.push(num);
		}
	}
	stack_size = S.size(); //스택의 합 구할때 필요

	for (int i = 0; i < stack_size; i++) {
		sum += S.top(); //맨 위 아니면 탐색이 원칙상 불가능하므로
		S.pop();
	}

	cout << sum;

	return 0;
}
