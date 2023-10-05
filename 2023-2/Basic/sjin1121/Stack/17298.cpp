#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v[s.top()] < v[i]) {
            result[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
