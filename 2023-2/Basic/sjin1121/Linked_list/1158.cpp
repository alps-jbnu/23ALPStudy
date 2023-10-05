#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	int n, k;
	int tmp;
	queue<int> q;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	cout << "<";
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k; j++) {
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		q.pop();
		if (q.empty())
			cout << ">";
		else
			cout << ", ";
		
	}
}	
