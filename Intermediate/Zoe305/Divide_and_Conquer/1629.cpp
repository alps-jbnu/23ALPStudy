#include <bits/stdc++.h>
using namespace std;


long long a, b, c, num;

long long sol(long long b){
    if(b == 0) return 1;
    if(b == 1) return a%c;

    num = sol(b/2)%c;
    if(b%2 == 0) return num*num%c; //짝수일 때
    return num*num%c * a%c; //홀수일 때
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    cout << sol(b);
}

/*
숫자의 범위가 크기 때문에 long long 자료형 이용할 것
a^b는 a^(b/2)의 제곱임을 이용해 분할정복으로 문제 풀기
다만 b가 짝수일 때와 홀수일 때 계산법이 다름에 주의하기
a^b는 수가 너무 크기 때문에 a 대신 a%c 구해서 이걸로 a를 대신함
재귀를 이용해 풀기에 sol 함수를 따로 구현해서 문제 품
*/