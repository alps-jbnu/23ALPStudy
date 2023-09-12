#include <iostream>
#include <vector>

using namespace std;

int fac(int a,int b,int c) {
    if (b == 1) {
        return a % c;
    }
    else {
        long long x = fac(a, b / 2,c);
        if (b % 2 == 0) {
            return (x*x) %c;
        }
        else {
            //(x* x *a) % c;
            return (((x * x) % c) * a) % c;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    
    cout<<fac(a,b,c);
}
