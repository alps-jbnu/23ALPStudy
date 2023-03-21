#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,a;
    int ans = 2000000001;
    cin >> n >> m;
    vector <int> vec;
    for(int i=0; i<n; i++) {
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int en =0;
    for(int st=0; st<n; st++) {
        while(en < n && vec[en] - vec[st] <m) en++;
        if(en == n) break;
        ans = min(ans, vec[en]-vec[st]);
    }

    // for(int i=0; i<n; i++) { //이분탐색
    //     int index = lower_bound(vec.begin(),vec.end(), vec[i]+m) - vec.begin();
    //     if(index != n) {
    //         ans = min(ans,abs(vec[index]-vec[i]));
    //     }
    // }
    cout << ans;
}