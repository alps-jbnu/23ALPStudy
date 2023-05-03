#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string exp;
	getline(cin, exp);

	int front = 0;
	int back = 0;
	string num;
	bool sub = false;		//앞쪽에 빼기가 있었는지

	for (int i = 0; i < exp.size(); i++) {
		if ('0' <= exp[i] && exp[i] <= '9') {	//숫자면 일단 저장
			num.push_back(exp[i]);
		}
		else if (exp[i] == '+') {		//더하기면
			if (sub) {					//빼기가 앞에 나왔으면
				back += stoi(num);		//back에 더해주고
			}
			else {					//빼기가 앞에 없었으면
				front += stoi(num);	//바로 front에 더해줌
			}
			num = "";				//num값 초기화
		}
		else if (exp[i] == '-') {	//빼기면
			if (sub) {				//이전에 빼기가 나온적이 있으면
				back += stoi(num);	//back에 앞 수까지 더하고
				front -= back;		//그만큼 front에서 빼줌
				back = 0;			//back초기화
			}
			else {					//빼기 안나왔으면
				front += stoi(num);		//그 앞까지 front에 더하고
				sub = true;			//빼기 나왔다고 표시
			}
			num = "";			//num초기화
		}
		if (i == exp.size() - 1) {		//마지막 숫자면
			if (sub) {				//빼기때랑 똑같이
				back += stoi(num);
				front -= back;
				back = 0;
			}
			else {
				front += stoi(num);
				sub = true;
			}
			num = "";
		}
	}

	cout << front;

}
