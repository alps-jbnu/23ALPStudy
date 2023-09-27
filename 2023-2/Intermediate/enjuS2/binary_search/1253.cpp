#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<climits>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int st = 0;
        int en = n - 1;
        while (st < en) {
            if (st == i) { st++; continue; };
            if (en == i) { en--; continue; };


            if (v[i] > v[st] + v[en]) {
                st++;
            }
            else if (v[st] + v[en] == v[i]) {
                ans++;
                break;
            }
            else {
                en--;
            }
        }
    }
    cout << ans;
    return 0;
}
