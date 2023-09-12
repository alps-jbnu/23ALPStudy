#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack <int> s;
    long long a, b, cnt = 0;
    cin >> a;
    for (int i = 0;i < a;i++) {
        cin >> b;

        while (!s.empty()&&s.top()<=b) {
            //cout << s.top() << "탑\n";
            s.pop();
        }
        cnt += (long long)s.size();
        s.push(b);
    }

    cout << cnt;

}
