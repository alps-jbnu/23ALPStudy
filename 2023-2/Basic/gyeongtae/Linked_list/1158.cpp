#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque <int> deq;
    deque <int> deq11;
    int a, b;
    int n = 1;
    cin >> a >> b;
    for (int i = 1;i <= a;i++) {
        deq.push_back(i);
    }
    while (!deq.empty()) {
        if (n == b) {
            deq11.push_back(deq.front());
            deq.pop_front();
            n = 1;
        }
        else {
            deq.push_back(deq.front());
            deq.pop_front();
            n++;
        }

    }
    cout << "<";
    for (int i = 0;i < a;i++) {
        cout << deq11.front();
        deq11.pop_front();
        if (i < a - 1) {
            cout << ", ";
        }
    }
    cout << ">";
}
