#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack <int> s1, s2;
    vector <int> v;
    int a, b;
    cin >> a;
    for (int i = 0;i < a;i++) {
        cin >> b;
        s1.push(b);
    }
    for (int i = 0;i < a;i++) {
        while (!s2.empty() && s1.top() >= s2.top()) {
            s2.pop();
        }
        if (s2.empty()) {
            s2.push(s1.top());
            s1.pop();
            v.push_back(-1);
        }
        else {
            v.push_back(s2.top());
            s2.push(s1.top());
            s1.pop();
        }
    }
    for (int i = 0;i < a;i++) {
        cout << v[a - i - 1] << " ";
    }
}
