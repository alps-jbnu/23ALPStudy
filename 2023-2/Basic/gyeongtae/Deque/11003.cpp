#include <iostream>
#include <deque>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c;
    deque <pair<int, int>> d;
    cin >> a >> b;
    for (int i = 0;i < a;i++) {
        if (!d.empty() && d.front().second < i - b + 1) {
            d.pop_front(); 
        }
        cin >> c;
        while (!d.empty() && d.back().first > c) {
            d.pop_back();
        }
        if (d.empty()) {
            d.push_front(make_pair(c, i));
        }
        else {
            if (c < d.front().first) {
                d.push_front(make_pair(c, i));
            }
            else {
                d.push_back(make_pair(c, i));
            }
        }
        cout << d.front().first << " ";
    }
}
