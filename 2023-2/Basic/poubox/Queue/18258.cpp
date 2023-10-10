#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if (op == "pop") {
            if (q.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (op == "size") {
            cout << q.size() << "\n";
        } else if (op == "empty") {
            if (q.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        } else if (op == "front") {
            if (q.empty())
                cout << "-1" << "\n";
            else
                cout << q.front() << "\n";
        } else if (op == "back") {
            if (q.empty())
                cout << "-1" << "\n";
            else
                cout << q.back() << "\n";
        }
    }

    return 0;
}
