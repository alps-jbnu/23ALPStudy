#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int stack_size;
    int k;
    cin >> k;
    stack<int> s;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        if (n == 0)
            s.pop();
        else
            s.push(n);
    }

    int result = 0;
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    cout << result;

    return 0;
}
