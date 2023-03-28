// Baekjoon - 9461번 파도반 수열

#include <iostream>
using namespace std;

long long d[101]; //피보나치수열과 비슷하면 long long으로 선언하자..
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    d[1]= 1;
    d[2]= 1;
    d[3]= 1;
    for(int i=4; i<=100; i++) 
        d[i] = d[i-2] + d[i-3];
    while(n--) {
        int a;
        cin >> a;
        cout << d[a]<<'\n';
    }
}