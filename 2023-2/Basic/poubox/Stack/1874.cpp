#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    vector<char> result;
    int n;
    cin >> n;
    int cnt = 1; // 수열을 나타내는 변수

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (cnt <= x) {
            s.push(cnt);
            cnt += 1;
            result.push_back('+');
        }
        if (s.top() == x) {
            s.pop();
            result.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';

    return 0;
}
