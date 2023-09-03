#include <bits/stdc++.h>

using namespace std;

long long int timesMod_recursion(int A, int B, int C){
    if (B == 0) return 1;

    if (B%2 == 1) return A * (timesMod_recursion(A,B/2,C) * timesMod_recursion(A,B/2,C) % C) % C;
    
    return timesMod_recursion(A,B/2,C) * timesMod_recursion(A,B/2,C) % C;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int A,B,C;

    cin >> A >> B >> C;

    cout << timesMod_recursion(A,B,C);

    return 0;
}
