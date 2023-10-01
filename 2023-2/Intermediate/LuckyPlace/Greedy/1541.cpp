#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;

	int num = 0;
	int sign = 1;					// +, - 구별, -가 한번이라도 나오면 이후는 쭉 -로 유지하기 위해 선언
	int ans = 0;
	for (char c : str)
	{
		if (c != '+' && c != '-')
		{
			num = num * 10 + (c - '0') * sign;		// flag에 따라 양수, 음수 결정
		}
		else if (c == '+')
		{
			ans += num;
			num = 0;
		}
		else                   // c == '-'
		{
			sign = -1;
			ans += num;
			num = 0;
		}
	}
	ans += num;			// 마지막 빠진 num추가
	cout << ans;

	return 0;
}
