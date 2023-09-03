#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int c){
    if(c==1){
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6-a-b, c-1);
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, c-1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;
    cout << (1<<K) - 1 << '\n';
    func(1, 3, K);
}