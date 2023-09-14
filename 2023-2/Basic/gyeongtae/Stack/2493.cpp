#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a;
    vector<pair<int, int>> v1;

    for (int i = 0; i < n; i++) {
        cin >> a;
        while (!v1.empty() && v1.back().first < a) {
            v1.pop_back();
        }
        if (v1.empty()) {
            cout << "0 ";
        }
        else {
            cout << v1.back().second + 1 << " ";
        }
        v1.push_back(make_pair(a, i));
    }

    return 0;
}
