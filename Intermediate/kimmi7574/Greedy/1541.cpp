#include <bits/stdc++.h>
using namespace std;

string str, num;
bool isMinus = false;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int min_val = 0;
	cin >> str;

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '-' || str[i] == '+' || i == str.size()) {
			if (isMinus) {	//true일 때만 빼기 연산 수행
				min_val -= stoi(num);
				num = "";	//num reset
			}
			else {			//isMinus가 false라면 더하기 연산 수행
				min_val += stoi(num);
				num = "";	//num reset
			}
		}
		else
			num += str[i];	//str[i]가 숫자 -> num에 숫자를 모음

		if (str[i] == '-') {
			isMinus = true;	//'-'연산자가 나오면 isMinus true로 변경
		}
	}

	cout << min_val;
}