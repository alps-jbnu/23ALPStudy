//hint) initial position(idx) of head: MX
//입력 둘쨰줄 첫 숫자가 있는 idx를 처음 위치(head)로 놓고 계속 풂.
#include<iostream>
using namespace std;
const int MX = 1005;
int dat[2 * MX + 1];
int head = MX; int tail = MX;

void push_front(int x) { dat[--head] = x; }
void push_back(int x) { dat[tail++] = x; }
void pop_front() { head++; }
void pop_back() { tail--; }
int front() { return dat[head]; }
int back() { return dat[tail - 1]; }
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;			//10 3
	for (int i = 0; i < N; i++) {
		push_back(i + 1);	//1 2 3 4 5 6 7 8 8 10
	}
	int op_cnt = 0;			//op_count: moveLeft or moveRight
	while (M--) {
		int target;
		cin >> target;		//2
		int steps = 0;		//steps: moveLeft count
		for (int i = head; i < head + N; i++) {
			if (dat[i] == target) steps = i - head;
		}
		while (front() != target) {
			if (steps < N - steps) {	//N - steps: moveRight count
				push_back(front());	//1 2 3 4 5 6 7 8 9 10 1
				pop_front();		//  2 3 4 5 6 7 8 9 10 1
			}
			else {	//moveLeft > moveRight --> moveRight
				push_front(back());
				pop_back();
			}
			op_cnt++;	//count sequence moving
		}
		pop_front();		//3 4 5 6 7 8 9 10 1
		N--;				//N=8
	}
	cout << op_cnt;
}
