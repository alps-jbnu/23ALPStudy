#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
//처음 -가 나타났을 때 괄호 생성
//괄호 생성후  -가 나타나면 괄호 닫기
//괄호 생성 후 +가 나타나면 계속 진행
//괄호 생성 후 바로 -가 나타나면 괄화 생성 삭제
using namespace std;
int N;

int ans;
int tmp;
int sign = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	cin >> input;
	for (char c : input) {
		if (c == '+' || c == '-') {
			ans += tmp * sign; // 처음 -가 나타났을 때 괄호 생성 괄호 생성 후 + 나타나면 계속 진행(sign으로 +를 -로 바꾸기)
			if (c == '-') {
				sign = -1;
			}
			tmp = 0;
		}
		else {
			tmp *= 10; // 자리수 올리면서 
			tmp += c - '0'; //더하기
		}
	}
	ans += tmp * sign;
	cout << ans;
	
}
