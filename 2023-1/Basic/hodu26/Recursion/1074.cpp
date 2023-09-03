#include <bits/stdc++.h>

using namespace std;

int z_recursion(int N, int r, int c){
    if (N == 1) return r*2 + c;

    return z_recursion(N-1,r/2,c/2)*4 + r%2*2 + c%2;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N,r,c;

    cin >> N >> r >> c;

    cout << z_recursion(N,r,c);

    return 0;
}
