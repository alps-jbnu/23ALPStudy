#include <iostream>
#include <deque>
using namespace std;

int main() {
    int a, b, c;
    deque <int> d, d2;
    deque <string> d3;
    cin >> a;
    for (int i = 0;i < a;i++) {
        cin >> b;
        d.push_back(b);
    }
    for (int i = 1;i <= a;i++) {
        d2.push_back(i);
        //cout <<"+\n";
        d3.push_back("+");
        while (!d.empty() && !d2.empty() && d.front() == d2.back()) {
            d2.pop_back();
            d.pop_front();
            //cout << "-\n";
            d3.push_back("-");
        }
    }
    if (d3.size() == 2 * a) {
        for (int i = 0;i < d3.size();i++) {
            cout << d3[i] << "\n";
        }
    }
    else {
        cout << "NO";
    }
}
