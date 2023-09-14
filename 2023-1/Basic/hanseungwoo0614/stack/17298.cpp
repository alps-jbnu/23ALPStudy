#include <bits/stdc++.h>
using namespace std;

int a[1000001];
int m[1000001];
stack<int> s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] < a[i]) 
        {
            m[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) {
        m[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++) cout << m[i] << " ";

    return 0;
}
