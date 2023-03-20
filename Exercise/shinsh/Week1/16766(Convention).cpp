#include<bits/stdc++.h>
using namespace std;

int n, m, c;
int CowTime[100005];

bool accept(int k) {
    int busCnt = 1;
    int first = 0;

    for (int i = 1; i < n; i++) {
        if (i - first >= c || CowTime[i] - CowTime[first] > k) {
        busCnt++;
        first = i;
        }
    }

    return busCnt <= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int st = 0;
    int en = 1000000000;

    cin >> n >> m >> c;

    for (int i = 0; i < n; i++) {
        cin >> CowTime[i];
    }

    sort(CowTime, CowTime + n);

    while (st <= en) {
        int mid = (st + en) / 2;

        if (accept(mid))
            en = mid - 1;
        else
            st = mid + 1;
    }
    cout << st;

    return 0;
}