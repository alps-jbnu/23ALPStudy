#include <iostream>
using namespace std;
const int MX = 500005;
int dat[MX];
int head = 0; int tail = 0;
void pop() {
	head = (head + 1 + MX) % MX;
}
int front() { return dat[head]; }
void push(int x) {
	dat[tail] = x;
	tail = (tail + 1 + MX) % MX;
}
//linear_Queue: OutOfBounds runtime error --> sol: circular_Queue
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N && N < MX; i++) {
		push(i + 1);
	}
	while (tail - head != 1) {
		pop();
		push(front());
		pop();
	}
	//if N=6 -> head=9, tail=10, dat[head]=4
	cout << front();
}
