#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque <int> deq;
    int a, b;
    string n, m;
    cin >> a;
    for (int i = 0;i < a;i++) {
        cin >> n;
        if (n == "push_back") {
            cin >> b;
            deq.push_back(b);
        }
        else if (n == "push_front") {
            cin >> b;
            deq.push_front(b);
        }
        else if (n == "pop_front") {
            if (!deq.empty()) {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
            else {
                cout << "-1\n";
            }
        }
        else if (n == "pop_back") {
            if (!deq.empty()) {
                cout << deq.back() << "\n";
                deq.pop_back();
            }
            else {
                cout << "-1\n";
            }
        }
        else if (n == "size") {
            cout << deq.size() << "\n";
        }
        else if (n == "empty") {
            cout << deq.empty() << "\n";
        }
        else if (n == "front") {
            if (!deq.empty()) {
                cout<<deq.front()<<"\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (n == "back") {
            if (!deq.empty()) {
                cout << deq.back() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
    }
}
