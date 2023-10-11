
#include <iostream>
#include <queue>
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);	// 지연시간 줄이기
	cin.tie(NULL);
	cout.tie(NULL);
	long n = 0;
	cin >> n;
	queue<int> Q;
	for (long i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		if (temp == "push") {
			int A;
			cin >> A;
			Q.push(A);

		}
		else if (temp == "pop") {
			if (Q.empty())	cout << "-1\n";
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (temp == "size") {
			cout << Q.size() << '\n';
		}
		else if (temp == "empty") {
			if (Q.empty())	cout << "1\n";
			else cout << "0\n";
		}
		else if (temp == "front") {
			if (Q.empty())	cout << "-1\n";
			else {
				cout << Q.front() << '\n';
			}
		}
		else if (temp == "back") {
			if (Q.empty())	cout << "-1\n";
			else {
				cout << Q.back() << '\n';
			}
		}
	}
}

