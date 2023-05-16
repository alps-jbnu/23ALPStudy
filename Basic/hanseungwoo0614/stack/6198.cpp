#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a = 0;

    int n;

    cin >> n;

    stack<int> s;
    long long h;

    while (1) {
        
        if (n == 0)
            break;
        cin >> h;
        while (!s.empty() && s.top() <= h)
            s.pop();
        a += s.size();
        s.push(h);
        n--;
    }
    cout << a;
    return 0;
}
