#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<climits>
using namespace std;

int a[1000];
int b[1000];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> v1;
    for (int i = 0; i < n; i++) {
        int sum = a[i];
        v1.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            v1.push_back(sum);
        }
    }

    vector<int> v2;
    for (int i = 0; i < m; i++) {
        int sum = b[i];
        v2.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += b[j];
            v2.push_back(sum);
        }
    }

    sort(v2.begin(), v2.end());
    long long ans = 0;
    for (int i : v1) {
        int diff = t - i;
        auto ub = upper_bound(v2.begin(), v2.end(), diff);
        auto lb = lower_bound(v2.begin(), v2.end(), diff);
        ans += (ub - lb);
    }
    cout << ans;
    return 0;
}
