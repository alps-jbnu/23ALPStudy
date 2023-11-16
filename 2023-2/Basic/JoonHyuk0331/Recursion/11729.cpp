#include <bits/stdc++.h>
using namespace std;

void move(int circle_no,int start,int end) {
	if (circle_no == 1) {
		cout << start << ' ' << end<<'\n';
		return;
	}

	move(circle_no-1, start, 6 - start - end);//4번을 시작점과 도착점이 아닌곳으로 뺸다
	cout << start << ' ' << end << '\n';//5번을 옮긴다
	move(circle_no - 1, 6 - start - end, end);//빼놨던 4번을 다시 5번위로 올려준다
}

int main(void) {
	int k;
	cin >> k;
	cout << int(pow(2, k) - 1) << '\n';//pow는 실수형으로 나와서 강제형변환 수학기억안나면 큐에넣고 하는방법도가능
	move(k, 1, 3);
	return 0;
}

