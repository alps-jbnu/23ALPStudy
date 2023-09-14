#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    int sum = 0;
    cin >> a;
    vector<int> n;
    for (int i = 0;i < a;i++) {
        cin >> b;
        if (b == 0) {
            n.pop_back();
        }
        else {
            n.push_back(b);
        }
    }
    for (int i = 0;i < n.size();i++) {
        sum += n.at(i);
    }
    cout << sum;
}
