#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
int dat[MX];
int head = 0, tail = 0;

void push(int x) { dat[tail++] = x; }
void pop() { head++; }
int size() { return tail - head; }
bool empty() { return !(tail - head); }
int front() { return dat[head]; }
int back() { return dat[tail - 1]; }

int main(void) {
	int N; cin >> N;
	while (N--) {
		string cmd; cin >> cmd;
		if (cmd == "push") {
			int val; cin >> val;
			push(val);
		}
		else if (cmd == "pop") {
			if (tail - head) {
				cout << front() << '\n';
				pop();
			}
			else cout << -1 << '\n';
		}
		else if (cmd == "size")
			cout << size() << '\n';
		else if (cmd == "empty")
			cout << empty() << '\n';
		else if (cmd == "front") {
			if (tail - head) cout << front() << '\n';
			else cout << -1 << '\n';
		}
		else {//back
			if (tail - head) cout << back() << '\n';
			else cout << -1 << '\n';
		}
	}
}
