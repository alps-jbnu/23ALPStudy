#include <iostream>
#include <algorithm>
using namespace std;

int multi(int a, int b, int c){
    if(b==1) return a % c;
    long long tmp = multi(a, b/2, c);
    if( b % 2 == 0 ){
        //짝수면 구한거 바로 덧셈
		return tmp * tmp % c;
	}
	else {
        //홀수면 나누고 a한번 더 곱셈
		return tmp * tmp % c * a % c;
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;   
    cin >> A >> B >> C;

    cout << multi(A,B,C);
}   
