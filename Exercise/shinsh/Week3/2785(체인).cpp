#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        v.push_back(len);
    }

    sort(v.begin(), v.end());

    while (true) {
        if (v.size() == 1)
            break;

        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();

        cnt++;
        v[0]--;

        if (v[0] == 0) {
            for (int i = 0; i < v.size() - 1; i++) {
                v[i] = v[i + 1];
            }
            v.pop_back();
        }
    }

    cout << cnt;

    return 0;
}