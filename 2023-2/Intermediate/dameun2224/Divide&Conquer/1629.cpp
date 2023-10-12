#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <list>
#include <tuple>
#include <stdlib.h>
using namespace std;

#define X first
#define Y second

using ll = long long;

ll pow(ll a, ll b, ll m) {
    if (b == 1) return a % m;
    ll val = pow(a, b / 2, m); // pow가 재귀적으로 계속 호출
    val = val * val % m;
    if (b % 2 == 0) return val;
    else if (b % 2 == 1) return val * a % m;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, b, c);

    return 0;
}
