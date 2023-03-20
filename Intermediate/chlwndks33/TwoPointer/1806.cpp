#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,s,a;
    vector<int> vec;
    cin >> n >> s;
    int ans = 100005;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    int en =0;
    int sum = vec[0];
    for(int st =0; st<n; st++) {
        while(en < n && sum < s) {
            en++;
            if(en!=n) sum += vec[en];
        }
        if(en == n) break;
        ans = min(ans, en-st+1);
        sum -= vec[st];
    }
    if(ans == 100005) ans = 0;
    cout << ans;

}