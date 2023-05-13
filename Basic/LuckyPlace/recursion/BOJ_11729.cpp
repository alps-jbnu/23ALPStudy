#include <iostream>
//#include <cmath>
using namespace std;

void hanoi(int a, int b, int n)		// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
{
	if (n == 1)
	{
		cout << a << ' ' << b << "\n";		// endl쓰면 시간초과
		return;
	}
	hanoi(a, 6-a-b, n - 1);
	cout << a << ' ' << b << "\n";
	hanoi(6 - a - b, b, n - 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;				// 하노이 원판 개수
	cin >> num;
	//cout << pow(2, num) - 1 << "\n";				// 맞왜틀?
	cout << (1<<num) - 1 << "\n";		// 2^n - 1 번 움직인다.
	hanoi(1, 3, num);
	return 0;
}