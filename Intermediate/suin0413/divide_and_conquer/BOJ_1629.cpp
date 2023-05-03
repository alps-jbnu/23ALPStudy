#include <iostream>
using namespace std;
using ll = long long;

ll POW(ll a, ll b, ll m){
    if(b==1) return a % m;
    ll val = POW(a, b/2, m);
    val = val * val % m;
    if(b%2 == 0) return val; // b가 짝수
    return val * a % m;
}

// 지수법칙 : a^(n+m) = a^n * a^m
// 모듈러 성질 : (a*b)%c = (a%c * b%c)%c
// 지수 b를 절반으로 계속 나눠서 계산

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll a, b, c;
  cin >> a >> b >> c;
  cout << POW(a,b,c);
}
