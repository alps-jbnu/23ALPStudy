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
    while (n--) {
        int in;
        cin >> in;
        v.push_back(in);
    }

    int l = 0;
    int r = v.size() - 1;
    int ans = v[l] + v[r];
    while (l < r) {
        int now = v[l] + v[r];
        if (abs(now) < abs(ans)) {
            ans = now;
        }

        if (now < 0) {
            l++;
        }
        else {
            r--;
        }
    }
    cout << ans;

    return 0;
}
