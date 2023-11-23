#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll A, B, C;

ll fun(ll a, ll b) {
	if (b == 1)//base case: a의1승이 되면 나눈 값을 반환
		return a % C;
	ll val = fun(a, b / 2);
	if (b % 2 == 0) {
		return val * val % C;//짝수면
	}
	else{
		return ((val * val) % C * a) % C;//홀수면 
	}
}

int main(void) {
	cin >> A >> B >> C;
	cout << fun(A, B);
}
