#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <list>
#include <tuple>
#include <set>
using namespace std;

#define X first
#define Y second

int n, m, t;
int a[100005];

int bs(int target) {
    int st = 0;
    int en = n - 1;
    
    while (st <= en) {
        int mid = (st + en) / 2;
        if (a[mid] < target) st = mid + 1;
        else if (a[mid] > target) en = mid - 1;
        else return 1;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a + n);

    cin >> m;
    while (m--) {
        cin >> t;
        cout << bs(t) << '\n';
    }


    return 0;
}
