#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

// 끝나는 시간과 다음 회의 시작 시간만 고려함.

int n, t, cnt;
vector<pair<int, int>> a;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        a.push_back({ n2, n1 });
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (a[i].second >= t) {
            cnt++;
            t = a[i].first;
        }
    }

    cout << cnt << '\n';

    return 0;
}
