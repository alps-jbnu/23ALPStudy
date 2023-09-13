#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    string n;
    queue<int> q;
    
    cin >> a;
    
    for (int i = 0; i < a; i++) {
        cin >> n;
        
        if (n == "push") {
            cin >> b;
            q.push(b);
        }
        else if (n == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else {
                cout << "-1" << '\n';
            }
        }
        else if (n == "size") {
            cout << q.size() << '\n';
        }
        else if (n == "empty") {
            cout << q.empty() << '\n';
        }
        else if (n == "front") {
            if (!q.empty()) {
                cout << q.front() << '\n';
            }
            else {
                cout << "-1" << '\n';
            }
        }
        else if (n == "back") {
            if (!q.empty()) {
                cout << q.back() << '\n';
            }
            else {
                cout << "-1" << '\n';
            }
        }
    }
    
    return 0;
}
