#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack <pair<int,int>> s;
    long long a, b, cnt = 0;
    cin >> a;
    for (int i = 0;i < a;i++) {
        cin >> b;

        while (!s.empty()&&s.top().first<b) {
            //cout << s.top() << " pop\n";
            cnt += s.top().second;
            s.pop();
        }
        if (s.empty()) {
            s.push(make_pair(b, 1));
        }
        else {
            if (s.top().first == b) {
                pair<int, int> cur = s.top();
                s.pop();
                cnt += cur.second;
                if (!s.empty()) {
                    cnt++;
                }
                cur.second++;
                s.push(cur);
            }
            else {
                s.push(make_pair(b, 1));
                cnt++;
            }
        }

    }

    cout << cnt;

}
