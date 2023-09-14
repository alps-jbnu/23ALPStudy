#include <iostream>
#include <queue>

using namespace std;


int main() {
    int a,b,c;
    string n, m;
    queue <int> q;
    cin >> a;
    for (int i = 0;i < a;i++) {
        cin >> n;
        if (n == "push") {
            cin >> b;
            q.push(b);
        }
        else if (n == "pop") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if (n == "size") {
            cout << q.size() << endl;
        }
        else if (n == "empty") {
            if (q.empty()) {
                cout << "1" << endl;
            }
            else {
                cout << "0" << endl;
            }
        }
        else if (n == "front") {
            if (!q.empty()) {
                cout << q.front() << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if (n == "back") {
            if (!q.empty()) {
                cout << q.back() << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
    }

}
