#include <bits/stdc++.h>
using namespace std;

int num[21];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 20; i++) num[i] = i;

    for(int i = 1; i <= 10; i++) {
        int a, b;
        cin >> a >> b;
        reverse(num+a, num+b+1);
    }

    for(int i = 1; i <= 20; i++) cout << num[i] << ' ';
}