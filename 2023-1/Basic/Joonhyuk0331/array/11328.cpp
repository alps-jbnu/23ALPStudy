#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void fun()
{
	int result;
	string aaa,bbb;
	cin >> aaa >> bbb;
	sort(aaa.begin(), aaa.end());
	sort(bbb.begin(), bbb.end());
	if (aaa.compare(bbb)==0)//같으면 0 이외엔 다른 숫자 반환
		cout << "Possible" << '\n';
	else
		cout << "Impossible" << '\n';
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) fun();
}
