#include <bits/stdc++.h>
using namespace std;

int n;
long long num[91]; //int형으로 선언해서 틀렸습니다가 떴었음

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    num[1] = 1;
    num[2] = 1;

    for(int i = 3; i <= n; i++)
        num[i] = num[i-1] + num[i-2];

    cout << num[n];
}