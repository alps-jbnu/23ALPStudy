#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a;
    int ans = 0;
    cin >> n;
    int count = 0;
    vector<int> vec;
    vector<int> sum;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            sum.push_back(vec[i]+vec[j]);
        }
    }
    sort(sum.begin(),sum.end());

    for(int i = n-1; i>0; i--) {
        for(int j = 0; j<i; j++) {
            int st = lower_bound(sum.begin(),sum.end(), vec[i] - vec[j]) - sum.begin();
            int en = upper_bound(sum.begin(),sum.end(), vec[i] - vec[j]) - sum.begin();
            if(en - st > 0) {
                ans = max(ans , vec[i]);
            }
        }
    }
    
    cout << ans;
}